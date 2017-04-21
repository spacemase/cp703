/*****************************************************************************
 * File: less10.c
 * Description:
 *   This program demonstrates recursive factorial algorithm
 *****************************************************************************/
#include <stdio.h>
#include <assert.h>

#define FACTNUM (5)
int factorial( int num )
{
    assert( num >= 0 );
    if ( num > 1 )
        return num * factorial( num - 1 );
    return 1;
}
int main( void )
{
    int val = 0;
    val = factorial( FACTNUM );
    printf( "Factorial of %d is %d\n", FACTNUM, val );
}

