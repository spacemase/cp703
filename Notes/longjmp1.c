#include <stdio.h>
#include <setjmp.h>

static jmp_buf state_;

static void funk1( void );
static void funk2( void );

int main( int argc, char **argv )
{
    switch ( setjmp( state_ ) )
    {
        case 0:
            printf( "First return from setjmp:\n" );
            funk1();
            break;
        case 1:
            printf( "Second return from setjmp:\n" );
            printf( "**MEMORY LEAK**\n" );
            printf( "**FILE LEFT OPEN**\n" );
            break;
        default:
            printf( "eh?\n" );
            break;
    };

    return 0;
}

static void funk1( void )
{
    void    *mem = malloc( 10 );
    FILE    *file   = fopen( "temp.txt", "w" );

    if ( mem == NULL || file == NULL )
        abort();

    funk2();
}

static void funk2( void )
{
    longjmp( state_, 1 );
}

