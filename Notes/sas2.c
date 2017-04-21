/*****************************************************************************
 * Sort and search an array of structs by an integer value.
 */
#include <string.h>
#include <stdlib.h>

typedef struct rec_s
{
    char    name[20];
    size_t  cid;
} REC_t, *REC_p_t;

static int sort_proc(
    const void *ptr1,
    const void *ptr2
);

static int search_proc(
    const void *ptr1,
    const void *ptr2
);

static REC_p_t lookup(
    size_t     key,
    REC_p_t    recs,
    size_t     count
);

int main( int argc, char **argv )
{
    /* to be sorted by cid */
    REC_t   recs[]  =
    {
        { "jane",      10512 },
        { "dick",      30722 },
        { "sally",     999   },
        { "spot",      333   },
        { "joe",       41222 },
        { "shmoe",     40231 },
        { "crocodile", 8888  }
    };

    size_t  test[] =
    {
        10512,
        8888,
        30722,
        40231,
        999,
        41222,
        333,
        11111
    };

    size_t      rec_count   = sizeof(recs)/sizeof(*recs);
    size_t      test_count  = sizeof(test)/sizeof(*test);
    size_t      inx     = 0;

    for ( inx = 0 ; inx < test_count ; ++inx )
    {
        REC_p_t rec = lookup( test[inx], recs, rec_count );
        if ( rec != NULL )
            printf( "%6d: %s\n", test[inx], rec->name );
        else
            printf( "%6d not in database\n", test[inx] );
    }

    return EXIT_SUCCESS;
}

static REC_p_t lookup( size_t key, REC_p_t recs, size_t count )
{
    static int  sorted  = 0;
    REC_p_t     rval    = NULL;

    /* Only sort the array once. */
    if ( !sorted )
    {
        qsort( recs, count, sizeof(REC_t), sort_proc );
        sorted = 1;
    }

    /* bsearch returns the *address* of an element in an array. Since
     * an element of our array is type REC_t, the address returned is
     * type REC_p_t.
     */
    rval = bsearch( &key, recs, count, sizeof(REC_t), search_proc );

    return rval;
}

static int sort_proc( const void *ptr1, const void *ptr2 )
{
    /* qsort passes the *addresses* of two elements in an array. An 
     * element in our array is type REC_t, so the passed pointers are
     * acutally type REC_p_t.
     */
    int         rcode   = 0;
    REC_p_t     rec1    = (REC_p_t)ptr1;
    REC_p_t     rec2    = (REC_p_t)ptr2;

    if ( rec1->cid < rec2->cid )
        rcode = -1;
    else if ( rec1->cid > rec2->cid )
        rcode = 1;
    else
        rcode = 0;

    return rcode;
}

static int search_proc( const void *ptr1, const void *ptr2 )
{
    /* For a key, bsearch passes whatever address we fed it, which is
     * type size_t*. For a record it passes the address of an element in
     * an array. The type of an element in our array is REC_t, so a
     * pointer to it will by type REC_p_t.
     */
    size_t      key     = *(size_t *)ptr1;
    REC_p_t     rec     = (REC_p_t)ptr2;
    int         rcode   = key - rec->cid;

    return rcode;
}

