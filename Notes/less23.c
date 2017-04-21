/******************************************************************************
 * FILE: less23.c
 * Description: Program to demonstrate variable argument parameter lists
 *****************************************************************************/
#include <stdio.h>
#include <stdarg.h>

#define INTVAL  (0)
#define DBLVAL  (1)
#define CHARVAL (2)
#define NOVAL   (3)

static void printval( int type, ... );
int main( void )
{
    printval( INTVAL,  42,
              CHARVAL, "Minnesota",
              DBLVAL,  3.14,
              CHARVAL, "Alabama",
              NOVAL
            );
}


static void printval( int type, ... )
{
    va_list argp;
    int     int_val = 0;
    double  dbl_val = 0;
    char    *char_val = NULL;

    va_start( argp, type );

    while( type != NOVAL )
    {
        switch( type )
        {
            case INTVAL:
                int_val = va_arg( argp, int );
                printf( "%d\n", int_val );
                break;
            case DBLVAL:
                dbl_val = va_arg( argp, double );
                printf( "%f\n", dbl_val );
                break;
            case CHARVAL:
                char_val = va_arg( argp, char * );
                printf( "%s\n", char_val );
                break;
            default:
                ;   /* Shouldn't ever get here */
        }
        type = va_arg( argp, int );
    }

    va_end( argp );
}


