/******************************************************************************
 *
 * File: zips4.c
 *
 * System: C Programming Advanced, Exercise 4
 * 
 * Description: 
 *
 * External Functions:
 *     ZIPS_parse_zips_rec
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 01-Apr-2005  Some Programmer     Original
 * 25-Apr-2007	Mason Jensen		Added code for ZIPS_create_bin_from_ascii()
 *****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "zips.h"

#define MAX_BUF (120)

/******************************************************************************
 * Function: ZIPS_create_bin_from_ascii
 * Description: read zips recs from an ASCII file and creates a
 *     binary file of ZIPS_data_t records 
 * Input:
 *   ascii_file - ASCII file with zips records
 *   binary_file - binary file with zips records
 * Output:
 *   recs_read - number of records parsed and written to binary file
 *   recs_skipped - number of records that failed parsing, excluding comments
 * Return:
 *    TRUE - successfully read ascii file and created binary file
 *    FALSE - did NOT successfully read ascii file and created binary file
 * Special Logic:
 *    If TRUE returned, binary file was created.
 *****************************************************************************/
extern int ZIPS_create_bin_from_ascii( char * ascii_file, char * binary_file,
                                       int * recs_read, int * recs_skipped )
{

}
