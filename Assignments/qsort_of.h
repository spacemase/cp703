#ifndef QSORT_OF_H_INCLUDED
#define QSORT_OF_H_INCLUDED
/******************************************************************************
 *
 * FILE: qsort_of.h
 *
 * System: ZIPS 
 *
 * 
 * Description: The include file for qsort_of dependencies 
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 01-Apr-2005  Some Programmer     Original
 *****************************************************************************/
extern void qsort_of( void *objects, int num, int size,
                      int (*cmp)(const void *, const void *) );
#endif

