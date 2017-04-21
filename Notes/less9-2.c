/******************************************************************************
 * FILE: less9-2.c
 * Description:  Demonstrate passing a function pointer to a function
 ******************************************************************************/

#include <stdio.h>

/* proto-type for function to pass */
void other_func( int color );

/* proto-type for function that takes 
 * as an argument pointer to a function that
 * take on int and returns void
 */
void func( int , void (*pass_func)(int color) );

int main( void )
{
    func( 3, other_func );
}

void other_func( int color )
{
    printf( "the color is %d\n", color );
}

void func( int color, void (*pass_func)(int color) )
{
    pass_func( color );
}

