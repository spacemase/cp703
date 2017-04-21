/******************************************************************************
 * FILE:  less9-1.c
 * Description:  FUNCTION POINTERS
 *****************************************************************************/
#include <stdio.h>


/* the function proto-type */
void my_func( void );    /* a function that takes no arguments
                          * and returns nothing */
void my_func( void )
{
    puts( "hello world" );
}
int main( void )
{
/* declaration of pointer to function */
    void (* func_ptr) ( void ); /* a pointer to a function
                                 * that takes no arguments
                                 * and returns nothing */
/* pointer initialization */
    func_ptr = my_func;    /* func_ptr points to a block of
                            * information needed to execute my_func */

/* and function execution */
    func_ptr();
}

