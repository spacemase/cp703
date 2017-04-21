#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h> 
#include <zips.h> 
#include <time.h> 
#include <linked_list.h> 
#include <windows.h> // not ANSI, for threads 

/* ---------------------------------------------------------------------------
* Constants
* --------------------------------------------------------------------------- */
#define YIELD() (Sleep( 1 )) 
#define MAX_PER_FILE (40) 
#define ZIPS_BIN ("zips.bin")
/* ---------------------------------------------------------------------------
* Global data
* --------------------------------------------------------------------------- */
static HANDLE list_lock_mutex_g   = NULL; 
static HANDLE list_output_thr_g   = NULL; 
static int shutdown_g             = FALSE; 
static LINKED_LIST_p_t zip_list_g = NULL; 
/* ---------------------------------------------------------------------------
* Prototypes
* --------------------------------------------------------------------------- */
static void safe_add_zip( ZIPS_data_t * zip ); 
static ZIPS_data_t * safe_remove_zip( void ); 
static DWORD WINAPI process_list_thread(void * p);
/* ---------------------------------------------------------------------------
* main
* --------------------------------------------------------------------------- */
int main( void ) 
{ 
    unsigned long threadid = 0;
    char * thread_arg = "thread args - could be any pointer";
    ZIPS_data_t * zips = NULL;
    int count = 0;
    if ( !ZIPS_read_recs_from_bin( ZIPS_BIN, &zips, &count ) )
    {
        printf( "Cannot read %s\n", ZIPS_BIN );
        exit( EXIT_FAILURE );
    }

    // initialize global data
    zip_list_g = LINKED_LIST_create_list( "zip list" );
    list_lock_mutex_g = CreateMutex( NULL, 0, NULL );
    list_output_thr_g = CreateThread( // Win32 Thread Creation
        NULL,                // security attributes
        0,                   // stack size - 0 use default
        process_list_thread, // thread main - function pointer
        thread_arg,          // argument to thread func - any pointer
        0,                   // creation flags - 0 user default
        &threadid);          
    srand( time( NULL ) );
    while ( 1 ) // loop until quit entered
    {
        ZIPS_state_zip_code_t zipcode = 0;
        char * err = NULL;
        int num = rand() % count;
        char buf[100];
        printf( "Next ZIP Code or Quit [[%05d]]==>", zips[num].zip_code );
        buf[0] = '\0';
        fgets(buf,50,stdin);
        if ( buf[0] == 'Q' || buf[0] == 'q' )
            break;
        safe_add_zip( &zips[num] );
        YIELD();
    }
    YIELD(); // give up context to let other threads do some work
    // shutdown 
    if ( list_lock_mutex_g ) 
    { 
        WaitForSingleObject(list_lock_mutex_g,INFINITE);
        CloseHandle( list_lock_mutex_g ); 
        list_lock_mutex_g = NULL; 
    } 
    if ( list_output_thr_g ) 
    { 
        unsigned long exitCode = EXIT_FAILURE; 
        GetExitCodeThread( list_output_thr_g, &exitCode ); 
        if ( exitCode == STILL_ACTIVE ) 
        { 
            TerminateThread( list_output_thr_g, exitCode );
        } 
        CloseHandle( list_output_thr_g ); 
        list_output_thr_g = NULL; 
    } 
} 
static DWORD WINAPI process_list_thread(void * p) 
{ 
    ZIPS_data_t * zip = NULL;
    FILE * fptr = fopen( "c:\\process_thread_out.txt", "w" ); 
    fprintf( fptr, "parameter was --> %s\n", (const char*)p);
    while ( !shutdown_g ) 
    { 
        zip = safe_remove_zip(); 
        if ( zip ) 
        { 
            fprintf( fptr, "%05d %s %s\n", zip->zip_code, zip->name, zip->state ); 
            fflush( fptr ); // debugging only
        } 
        Sleep( 100 ); // a kludge - better to wait for events then to continously pole the list
    }
    // after shutdown, dump what's left in the list without waiting or releasing context
    do
    { 
        if ( (zip = safe_remove_zip()) != NULL )
            fprintf( fptr, "%05d %s %s\n", zip->zip_code, zip->name, zip->state ); 
    } while ( zip );
    if ( fptr ) fclose( fptr ); 
    return EXIT_SUCCESS; 
} 
static void safe_add_zip( ZIPS_data_t * zip ) 
{ 
    WaitForSingleObject(list_lock_mutex_g,INFINITE); 
    LINKED_LIST_add_to_list( zip_list_g, zip ); 
    ReleaseMutex(list_lock_mutex_g); 
} 
static ZIPS_data_t * safe_remove_zip( void ) 
{ 
    ZIPS_data_t * zip = NULL; 
    WaitForSingleObject(list_lock_mutex_g,INFINITE); 
    zip = LINKED_LIST_remove_head( zip_list_g ); 
    ReleaseMutex(list_lock_mutex_g); 
    return zip; 
} 
---------------  ADD THIS TO LINKED_LIST.c --------------------------------
extern void * LINKED_LIST_remove_head( 
                                      LINKED_LIST_t * list                  /* <I> the list */ 
                                      ) 
{ 
    void * user_data = NULL; 
    if ( list && list->head ) 
    { 
        item_t * item = list->head; 
        user_data = item->user_data; 
        if ( list->head == list->tail ) // only one item in the list 
        { 
            list->head = list->tail = NULL; 
        } 
        else 
        { 
            list->head = list->head->next; 
        } 
    } 
    return user_data; 
} 

---------------  ADD THIS TO LINKED_LIST.h --------------------------------

/*---------------------------------------------------------------------------* 
* LINKED_LIST_remove_head 
* Description: remove head from list
* Returns: pointer to user data list not empty, otherwise NULL
*---------------------------------------------------------------------------*/ 
extern void * LINKED_LIST_remove_head( 
            LINKED_LIST_p_t list                  /* <I> the list */ 
            );


