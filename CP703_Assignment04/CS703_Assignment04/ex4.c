/******************************************************************************
 *
 * File: ex4.c
 *
 * System: C Programming Advanced, Exercise 4
 * 
 * Description: This program tests the ZIPS_parse_zips_rec function.
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 01-Apr-2005  Some Programmer     Original
 * 18-Apr-2007	Mason Jensen		Added test data
 * 25-Apr-2007	Mason Jensen		Added call to ZIPS_create_bin_from_ascii() 
 *									to create zips.bin from zips.txt.
 *****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "zips.h"

/******************************************************************************
 * constants
 *****************************************************************************/

/******************************************************************************
 * typedefs
 *****************************************************************************/

/******************************************************************************
 * prototypes
 *****************************************************************************/

/******************************************************************************
 * main function
 *
 *	1. Makes on call to the ZIPS_create_bin_from_ascii() function to create 
 *		zips.bin binary file from zips.txt ASCII file.
 *	2. Reports success/failure to create binary file.
 *	3. Reports number of records written to binary file.
 *	4. Reports number of records skipped.
 *
 *****************************************************************************/
int main( void )
{
	int i = 0;
    ZIPS_data_t zips_rec;
	char foo[80];
	char *zips_str[25] =  { "53,98101,WA,SEATTLE,122.35032,47.62180,516259,0.0",
							"\"44\",\"02804\",\"RI\",\"ASHAWAY\",71.783745,41.423054,2472,0.002463",
							" 31 , 68949 , NE , HOLDREGE , 99.37551 , 40.44058 , 5671 ,0.1 ",
							"31,69341,NE,TERRYTOWN,\"103.66845\",\"41.85000\",\"656\",\"0.2\"",
							"\" 31 \",\" 69341 \",\" NE \",\" GERING \",\" 103.662896 \",\" 41.821993 \",\" 11631 \",\" 0.3 \"",
							" \"08\" , \"80521\" , \"CO\" , \"FORT COLLINS\" , \"105.06848\" , \"40.55555\" , \"87758\" , \"0.4\" ",
							"08,80014,CO,AURORA,104.72977,39.71226,222103,0.5",
							"08,80010,CO,DENVER,104.87265,39.76803,467610,0.6",
							"-1,00001,XY,SHANGRI-LA,-180,-180,0,0",
							"100,99999,XY,SHANGRI-LA,180,180,144000,1.1",
							"0,0,XY,SHANGRI-LA,-180,-180,0,0",
							"99,100000,XY,SHANGRI-LA,180,180,144000,1.1",
							"0,00001,X,SHANGRI-LA,-180,-180,0,0",
							"99,99999,XYZ,SHANGRI-LA,180,180,144000,1.1",
							"0,00001,XY,,-180,-180,0,0",
							"99,99999,XY,SHANGRI-LA HYPERBORIA,180,180,144000,1.1",
							"0,00001,XY,SHANGRI-LA,-180.00001,-180,0,0",
							"99,99999,XY,SHANGRI-LA,180.00001,180,144000,1.1",
							"0,00001,XY,SHANGRI-LA,-180,-180.00001,0,0",
							"99,99999,XY,SHANGRI-LA,180,180.00001,144000,1.1",
							"0,00001,XY,SHANGRI-LA,-180,-180,-1,0",
							"99,99999,XY,SHANGRI-LA,180,180,144000,-0.1",
							"0,00001,XY,SHANGRI-LA,-180,-180,0",
							"0,00001,XY,SHANGRI-LA,-180,-180,0,0",
							"99,99999,XY,SHANGRI-LA,180,180,144000,1.1",
							};

	for ( i = 0; i < 25; ++i )
	{
	    if ( ZIPS_parse_zips_rec( zips_str[i], &zips_rec ) )
		{
			printf( "Parsed this string: %s\n", zips_str[i] );
			ZIPS_print_recs( &zips_rec, 1 );
		}
		else
		{
			fprintf( stderr, "Failed to parse string %d >>%s<<\n", i, zips_str[i] );
	    }
		puts( "\nPress enter to continue...\n" );
		gets( foo );
	}

    return EXIT_SUCCESS;
}


