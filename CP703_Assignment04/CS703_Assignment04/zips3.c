/******************************************************************************
 *
 * File: zips3.c
 *
 * System: C Programming Advanced, Exercise 3
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
 * 18-Apr-2007	Mason Jensen		Added code for ZIPS_parse_zips_rec()
 *****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "zips.h"

#define MAX_BUF (120)

/******************************************************************************
 * ZIPS record validation criteria:
 *
 * General
 * Any field may have leading and/or trailing spaces. Any field may be
 * quoted. For simplicity, don't worry about validating balanced quotes.
 * A record is valid only if all fields are present and valid. Fields
 * are separated by commas. The order the fields appear in is as follows:
 *      FIPS code
 *      Zip code
 *      State
 *      Name
 *      Longitude
 *      Latitude
 *      Population
 *      Allocation
 * 
 * Alphanumeric fields
 * May contain any character; leading and/or trailing spaces and quotes
 * must be stripped.
 *
 * FIPS code
 * Must be an integer value between 0 and 99.
 *
 * Zip code
 * Must be an integer value between 1 and 99999.
 *
 * State
 * Must be a two character alphanumeric value.
 *
 * Name
 * Must be an alphanumeric value bewteen one and twenty characters
 * in length.
 *
 * Longitude
 * Must be a floating point value between -180 and 180. (Note:
 * integers, e.g. 99, are valid floating point numbers.)
 *
 * Latitude
 * Must be a floating point value between -180 and 180. (Note:
 * integers, e.g. 99, are valid floating point numbers.)
 *
 * Population
 * Must be an integer greater than or equal to 0.
 *
 * Allocation
 * Must be an integer greater than or equal to 0.
 */

/******************************************************************************
 * Function: ZIPS_parse_zips_rec
 * Description:  parse the input buffer zips information and
 *              initialize the structure fields
 * Input:
 *    buf - char array that contains zips information 
 * Output:
 *    zips_rec - pointer to zips record
 * Return:
 *    TRUE - translated buffer without error
 *    FALSE - error translating buffer
 * Special Logic:
 *   If FALSE returned, parse_struct is NOT modified 
 *****************************************************************************/
extern int ZIPS_parse_zips_rec( char * buf, ZIPS_data_p_t zips_rec )
{
	int rcode = TRUE;
	ZIPS_data_t temp_rec;
	char *err = NULL;
    char *token = NULL;
	char *temp = NULL;
    char buffer[MAX_BUF];

    strncpy( buffer, buf, MAX_BUF - 1 );
    buffer[MAX_BUF - 1] = '\000';

	/* FIPS token */
	token = strtok (buffer, "," );
	if ( token == NULL )
		rcode = FALSE;
	else
	{
		token += strspn(token, " \"");
		temp_rec.fips_code = strtol(token, &err, 0);
		if ( /*strcmp(err, "") != 0 || */ temp_rec.fips_code < 0 || temp_rec.fips_code > 99)
		{
			rcode = FALSE;
			/* err = NULL; */
		}
	}

	/* ZIP token */
	token = strtok( NULL, "," );
	if ( token == NULL )
		rcode = FALSE;
	else
	{
		token += strspn(token, " \"");
		temp_rec.zip_code = strtol(token, &err, 0);
		if ( /*strcmp(err, "") != 0 || */ temp_rec.zip_code < 1 || temp_rec.zip_code > 99999 )
		{
			rcode = FALSE;
			/* err = NULL; */
		}
	}

	/* State token */
	token = strtok( NULL, "," );
	if ( token == NULL )
		rcode = FALSE;
	else
	{
		token += strspn(token, " \"");
		strcpy( temp_rec.state, token );
		temp = strpbrk( temp_rec.state, " \"");
		if ( temp != NULL )
			*temp = '\000';
		if ( strlen(temp_rec.state) != ZIPS_STATE_LEN )
			rcode = FALSE;
	}

	/* Name token */
	token = strtok( NULL, "," );
	if ( token == NULL )
		rcode = FALSE;
	else
	{
		token += strspn(token, " \"");
		strcpy( temp_rec.name, token );
		temp = strpbrk( temp_rec.name, " \"");
		if ( temp != NULL )
			*temp = '\000';
		if ( strlen(temp_rec.name) < 0 || strlen(temp_rec.name) > ZIPS_CODE_NAME_LEN )
			rcode = FALSE;
	}

	/* Longitude token */
	token = strtok( NULL, "," );
	if ( token == NULL )
		rcode = FALSE;
	else
	{
		token += strspn(token, " \"");
		temp_rec.longitude = strtod(token, &err);
		if ( /*strcmp(err, "") != 0 || */ temp_rec.longitude < -180 || temp_rec.longitude > 180 )
		{
			rcode = FALSE;
			/* err = NULL; */
		}
	}

	/* Latitude token */
	token = strtok( NULL, "," );
	if ( token == NULL )
		rcode = FALSE;
	else
	{
		token += strspn(token, " \"");
		temp_rec.latitude = strtod(token, &err);
		if ( /*strcmp(err, "") != 0 || */ temp_rec.latitude < -180 || temp_rec.latitude > 180 )
		{
			rcode = FALSE;
			/* err = NULL; */
		}
	}

	/* Population token */
	token = strtok( NULL, "," );
	if ( token == NULL )
		rcode = FALSE;
	else
	{
		token += strspn(token, " \"");
		temp_rec.population = strtol(token, &err, 0);
		if ( /*strcmp(err, "") != 0 || */ temp_rec.population < 0 )
		{
			rcode = FALSE;
			/* err = NULL; */
		}
	}

	/* Allocation token */
	token = strtok( NULL, "," );
	if ( token == NULL )
		rcode = FALSE;
	else
	{
		token += strspn(token, " \"");
		temp_rec.allocation = strtod(token, &err);
		if ( /*strcmp(err, "") != 0 || */ temp_rec.allocation < 0 )
		{
			rcode = FALSE;
			/* err = NULL; */
		}
	}

	if ( rcode )
		*zips_rec = temp_rec;
	return rcode;
}




