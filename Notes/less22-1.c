/******************************************************************************
 * FILE: less22-1.c
 * Description: program to set and test bits
 *****************************************************************************/
#include <stdio.h>

/* these must be powers of 2 (1,2,4,...) */
#define STATIC   (02)  /* second bit for static */
#define EXTERNAL (04)  /* third bit for external */

int main( void )
{
    unsigned int flag = 0;

  /*
   * flag | EXTERNAL
   *
   *    0000
   *  | 0100
   *  ------
   *    0100
   */
    flag |= EXTERNAL;                /* turns EXTERNAL bit on */

  /*
   * flag & EXTERNAL
   *
   *    0100
   *  & 0100
   *  ------
   *    0100
   */
    if ( (flag & EXTERNAL) != 0 )    /* TRUE if EXTERNAL bit set */
        puts( "EXTERNAL flag is set\n" );

   /*
    * flag & ~(EXTERNAL)
    *
    * ~(EXTERNAL) --> ~(0100) --> (1011)
    *
    *   0100
    * & 1011
    * ------
    *   0000
    */
    flag &= ~(EXTERNAL);                /* turns EXTERNAL bit off */

   /*
    * flag & EXTERNAL
    *
    * ~(EXTERNAL) --> ~(0100) --> (1011)
    *
    *   0100
    * & 1011
    * ------
    *   0000
    */
    if ( (flag & EXTERNAL) == 0 )       /* TRUE if EXTERNAL bit off */
        puts( "EXTERNAL flag is off\n" );

   /*
    * flag |= EXTERNAL | STATIC
    *
    *   0100
    * | 0010
    * ------
    *   0110
    */
    flag |= EXTERNAL | STATIC;          /* turns EXTERNAL and STATIC bits on */

   /* 
    *  flag & EXTERNAL | STATIC 
    *
    *   0110    flag
    * & 0100    EXTERNAL
    * ------
    *   0100
    *
    *   0100    flag & EXTERNAL
    * | 0010    STATIC
    * ------
    *   0110
    */
    if ( ( flag & (EXTERNAL | STATIC) ) != 0 )    /* TRUE if either bit is on */
        puts( "EXTERNAL or STATIC bit set\n" );

   /* 
    * flag & ~(EXTERNAL | STATIC)
    * 
    *   0100
    * | 0010
    * ------
    *   0110 --> ~(0110) --> 1001
    *
    *   1001
    * & 0110
    * ------
    *   0000
    */
    flag &= ~( EXTERNAL | STATIC );              /* turn them off */

   /*
    * flag & EXTERNAL & STATIC
    *
    *   0100
    * & 0010
    * ------
    *   0110
    *  
    *   0000
    * & 0110
    * ------
    *   0000
    */
    if ( (flag & (EXTERNAL & STATIC )) == 0 )         /* TRUE if both bits off */
        puts( "both flags off" );

}

