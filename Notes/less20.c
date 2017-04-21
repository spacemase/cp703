/******************************************************************************
 * FILE: less20.c
 * Description: Program to demonstrate longjmp and signals
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>


static jmp_buf context;

static void sig_handler( int sig )
{
    if ( sig == SIGINT )
        puts( "SIGINT encountered" );
    longjmp( context, 1 );
}

int main( void )
{
    int error = 0;
    void (*rcode)( int );

    rcode = signal( SIGINT, sig_handler );
    if ( rcode == SIG_ERR )
        puts( "ERROR: Unable to establish signal handler" );
    else if ( rcode == SIG_DFL )
        puts( "Establish signal handler" );
    else
        puts( "eh?" );
    error = setjmp( context );
    if ( error == 0 )
    {
        puts( "Main processing" );
        raise( SIGINT );
    }
    else
    {
        printf( "Recovery block - error %d\n", error );
    }
    return EXIT_SUCCESS;
}



