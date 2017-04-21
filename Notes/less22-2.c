/******************************************************************************
 * FILE: less22-2.c
 * Description: program to demonstrate bit fields
 *****************************************************************************/
#include <stdio.h>
/* bit fields */
struct
{
    unsigned int is_keyword : 1; /* number represents field width in bits */
    unsigned int is_extern  : 1; /* they do not have addresses */
    unsigned int is_static  : 1; /* so & operator cannot be applied */
} flags;

int main( void )
{
/* turn bits on */
    flags.is_extern = 1;

/* turn bits off */
    flags.is_static = 0;

/* test bits */
    if ( flags.is_static == 0 && flags.is_extern == 1 )
        printf( "static off and extern on!!\n" );

}

