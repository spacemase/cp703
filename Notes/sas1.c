/*****************************************************************************
 * Sort and search an array of structs by a string value.
 */
#include <string.h>
#include <stdlib.h>

static const char *lookup(
    const char *key,
    const char **phonebook,
    size_t     count
);

static int sort_proc(
    const void *ptr1,
    const void *ptr2
);

static int search_proc(
    const void *ptr1,
    const void *ptr2
);

int main( int argc, char **argv )
{
    /* The first ten characters of a string constitue a name. The rest is a 
     * phone number.
     */
    const char *phonebook[]   =
    {
        "jane       313-221-8927",
        "dick       424-877-3232",
        "sally      212-437-1212",
        "spot       999-455-2222",
        "joe        425-661-7367",
        "shmoe      602-444-9139",
        "crocodile  800-333-2121"
    };

    const char *test[]  =
    {
        "jane",
        "crocodile",
        "dick",
        "shmoe",
        "sally",
        "spot",
        "peabody"
    };

    size_t      pb_count    = sizeof(phonebook)/sizeof(*phonebook);
    size_t      test_count  = sizeof(test)/sizeof(*test);
    size_t      inx     = 0;

    for ( inx = 0 ; inx < test_count ; ++inx )
    {
        const char* rec = lookup( test[inx], phonebook, pb_count );
        if ( rec != NULL )
            puts( rec );
        else
            printf( "%s not in phonebook\n", test[inx] );
    }

    return EXIT_SUCCESS;
}

static const char*
lookup( const char *key, const char **phonebook, size_t count )
{
    static int  sorted  = 0;
    const char  **prec  = NULL;
    const char  *rval   = NULL;

    if ( !sorted )
    {
        qsort( phonebook, count, sizeof(char *), sort_proc );
        sorted = 1;
    }

    /* bsearch returns the *address* of an element in an array. Since
     * an element of our array is type char*, the address returned is
     * type char**.
     */
    prec = bsearch( key, phonebook, count, sizeof(char *), search_proc );
    if ( prec != NULL )
        rval = *prec;

    return rval;
}

static int sort_proc( const void *ptr1, const void *ptr2 )
{
    /* qsort passes the *addresses* of two elements in an array. An 
     * element in our array is type char*, so the passed pointers are
     * acutally type char**.
     */
    int         rcode   = 0;
    const char  *str1   = *(const char **)ptr1;
    const char  *str2   = *(const char **)ptr2;
    int         cmp     = strcmp( str1, str2 );

    if ( cmp < 0 )
        rcode = -1;
    else if ( cmp > 0 )
        rcode = 1;
    else
        rcode = 0;

    return rcode;
}

static int search_proc( const void *ptr1, const void *ptr2 )
{
    /* For a key, bsearch passes whatever address we fed it, which is
     * type char*. For a record it passes the address of an element in
     * an array. The type of an element in our array is char*, so a
     * pointer to it will by type char**.
     */
    const char  *key    = ptr1;
    const char  *rec    = *(const char **)ptr2;
    size_t      count   = strlen( key );
    int         rcode   = strncmp( key, rec, count );

    return rcode;
}


