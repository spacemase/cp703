/******************************************************************************
 *
 * File: ex2.c
 *
 * System: C Programming Advanced, Exercise 2
 * 
 * Description: This program tests parsing a simple string
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 01-Jan-2005  Some Programmer     Original
 *****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

/***************************************************************************
 * structure declarations
 ***************************************************************************/
/* Do not change this number */
#define NAME_LEN 20

#ifndef TRUE
#define TRUE  1
#endif
#ifndef FALSE
#define FALSE 0
#endif

/***************************************************************************
 * structure declarations
 ***************************************************************************/
struct parse_s
{
    char name[NAME_LEN + 1];
    double value;
};

/***************************************************************************
 * prototypes
 ***************************************************************************/
static void print_parse( char * parse_str, struct parse_s * parse_struct );
static int parse_sscanf( char * in_str, struct parse_s * parse_struct );
static int parse_strtok( char * in_str, struct parse_s * parse_struct );

/***************************************************************************
 * main function
 ***************************************************************************/
int main( void )
{
    int inx = 0;
    struct parse_s parse;
    char * test[] = { "123.456        some-number-name",
                      "  314.159        pi*100",
                      "314159         pi*100000",
                      "0.314159       pi/10",
                      "123.45         123.45  ",
                      "314.159        pi*100  ",
                      "-123.456       a-neg-number ",
                      "0.0            zero-number",
                      "0              another-zero",
                      /** these may or may not fail - depends on definition **/
                      "123.456        some-really-long-name-string",
                      "3.1.4159       pi",
                      "499.999        some-number    299.999  extra ",
                      /** these should fail */
                      "",
                      "no-num",
                      "invalid-num       xxx",
                      "name-in-wrong-position  123.45",
                      "123.45  " };
#ifdef MY_DEBUG
    freopen( "logfile.txt", "w", stdout );
    freopen( "errfile.txt", "w", stderr );
#endif

    puts( "********************" );
    puts( "Testing parse_strtok" );
    puts( "********************" );
    for ( inx = 0; inx < sizeof(test)/sizeof(char *); inx ++ )
    {
        /* clear each structure with memset before each *TEST* */
        memset( &parse, 0, sizeof( parse) );
        if ( parse_strtok( test[inx], &parse ) )
            print_parse( test[inx], &parse );
        else
            fprintf( stderr, "Failed to parse >>%s<<\n", test[inx] );
    }

    puts( "********************" );
    puts( "Testing parse_sscanf" );
    puts( "********************" );
    for ( inx = 0; inx < sizeof(test)/sizeof(char *); inx ++ )
    {
        /* clear each structure with memset before each *TEST* */
        memset( &parse, 0, sizeof( parse) );
        if ( parse_sscanf( test[inx], &parse ) )
            print_parse( test[inx], &parse );
        else
            fprintf( stderr,  "Failed to parse >>%s<<\n", test[inx] );
    }

    return EXIT_SUCCESS;
}

/***************************************************************************
 * Function: print_parse
 * Description: print string and structure content
 * Input:
 *   parse_str - string that was parsed
 *   parse_struct - structure string was parsed in to
 * Output:
 *   none
 * Return:
 *   none
 * Special Logic:
 *   none
 ***************************************************************************/
static void print_parse( char * parse_str, struct parse_s * parse_struct )
{
    printf( "Success parsed >>%s<< to >>%s<< and %f\n",
         parse_str, parse_struct->name, parse_struct->value );
}

/***************************************************************************
 * Function: parse_sscanf
 * Description: parse string using sscanf
 * Input:
 *   in_str - string to parse
 * Output:
 *   parse_struct - pointer to structure to add data to
 * Return:
 *   TRUE - sucessfully parsed and updated parse_struct
 *   FALSE - some error encountered
 * Special Logic:
 *   When FALSE returned, parse_struct is NOT modified 
 *   Input and Output pointers must be non-NULL.
 ***************************************************************************/
static int parse_sscanf( char * in_str, struct parse_s * parse_struct )
{
    return FALSE;
}

/***************************************************************************
 * Function: parse_strtok
 * Description: parse string strtok and other stdlib functions
 * Input:
 *   in_str - string to parse
 * Output:
 *   parse_struct - pointer to structure to add data to
 * Return:
 *   TRUE - sucessfully parsed and updated parse_struct
 *   FALSE - some error encountered
 * Special Logic:
 *   When FALSE returned, parse_struct is NOT modified 
 *   Input and Output pointers must be non-NULL.
 ***************************************************************************/
static int parse_strtok( char * in_str, struct parse_s * parse_struct )
{
    return FALSE;
}


