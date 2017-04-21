#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE (100)

static void ex1_1(
    void
);

static void ex1_2(
    void
);

static void ex1_3(
    void
);

int main( int argc, char **argv )
{
    ex1_1();
    ex1_2();
    ex1_3();

    return EXIT_SUCCESS;
}

static void ex1_1( void )
{
    char *target    = "abc, def, ghi, spot, jane and sally";
    char *token     = NULL;
    char buffer[BUF_SIZE];

    puts( "Begin strtok example 1-1");
    /* strtok modifies the string that it tokenizes. Since target points to 
     * a string constant we can't operate on it directly, so first copy it
     * to a non-constant buffer. I will use strncpy for "safety."
     */
    strncpy( buffer, target, BUF_SIZE - 1 );
    buffer[BUF_SIZE - 1] = '\000';

    /* On the first call to strtok we pass buffer; strtok stores the address
     * of buffer internally so for subsequent calls I will just pass NULL.
     * For token delimiters I will specify space and comma.
     */
    token = strtok( buffer, ", " );

    /* strtok returns NULL when there are no more tokens to parse. */
    while ( token != NULL )
    {
        printf( "Token = \"%s\"\n", token );
        token = strtok( NULL, ", " );
    }
    
    puts( "End strtok example 1-1\n--------------------" );
}

static void ex1_2( void )
{
    char *target    = "abc, def, ghi, spot, jane and sally";
    char *token     = NULL;
    char buffer[BUF_SIZE];

    puts( "Begin strtok example 1-2");
    strncpy( buffer, target, BUF_SIZE - 1 );
    buffer[BUF_SIZE - 1] = '\000';

     /* For token delimiters I will specify comma only. */
    token = strtok( buffer, "," );

    /* strtok returns NULL when there are no more tokens to parse. */
    while ( token != NULL )
    {
        printf( "Token = \"%s\"\n", token );
        token = strtok( NULL, "," );
    }
    
    puts( "End strtok example 1-2\n--------------------" );
}

static void ex1_3( void )
{
    char *target    = "abc,def,ghi,spot,jane and sally";
    char *token     = NULL;
    char buffer[BUF_SIZE];

    puts( "Begin strtok example 1-3");
    strncpy( buffer, target, BUF_SIZE - 1 );
    buffer[BUF_SIZE - 1] = '\000';

     /* For token delimiters I will specify comma only. */
    token = strtok( buffer, "," );

    /* strtok returns NULL when there are no more tokens to parse. */
    while ( token != NULL )
    {
        printf( "Token = \"%s\"\n", token );
        token = strtok( NULL, "," );
    }
    
    puts( "End strtok example 1-3\n--------------------" );
}

