/*****************************************************************************
 * Demonstrates how to walk through an array when you don't know the
 * type of the array at compile time.
 */
#include <stdio.h>
#include <stdlib.h>

#define CARD( a ) (sizeof((a)) / sizeof(*(a)))

typedef struct rec_s
{
    char    name[20];
    int     cid;
} REC_t, *REC_p_t;

static void put_array(
    const void  *array,
    size_t      count,
    size_t      size,
    void (*put_proc)( const void * )
);

static void put_int(
    const void *ptr
);

static void put_string(
    const void *ptr
);

static void put_rec(
    const void *ptr
);

int main( int argc, char **argv )
{
    int     iarr[]  = 
    { 10, -20, 30, -40, 50, -60 };

    char    *sarr[] =
    { "dick", "jane", "sally", "spot", "manny", "moe", "jack" };

    REC_t   rarr[]  =
    {
        { "sally", 100 },
        { "jane",  200 },
        { "dick",  300 },
        { "shmoe", 150 }
    };

    int     inx     = 0;

    put_array( iarr, CARD( iarr ), sizeof(int),   put_int );
    put_array( sarr, CARD( sarr ), sizeof(char*), put_string );
    put_array( rarr, CARD( rarr ), sizeof(REC_t), put_rec );

    return EXIT_SUCCESS;
}

/*****************************************************************************
 * Walks through a "generic" array, that is, an array with an unknown type.
 * Prints the value of every element of the array.
 *
 * array:    array to walk through
 * count:    number of elements in the array
 * size:     size of an element in the array
 * put_proc: function that knows how to print an element of the array
 */
static void
put_array( const void *array,
           size_t count,
           size_t size,
           void (*put_proc)( const void * )
         )
{
    size_t      inx     = 0;
    const char  *arr    = array;

    for ( inx = 0 ; inx < count ; ++inx )
    {
        const char  *next   = arr + inx * size;
        put_proc( next );
    }
}

static void put_int( const void *ptr )
{
    const int   *next   = ptr;
    printf( "%d\n", *next );
}

static void put_string( const void *ptr )
{
    const char  *next   = *(char **)ptr;
    printf( "%s\n", next );
}

static void put_rec( const void *ptr )
{
    const REC_p_t   rec = (const REC_p_t)ptr;
    printf( "%3d, %s\n", rec->cid, rec->name );
}

