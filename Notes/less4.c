/*****************************************************************************
 * File: less4.c
 * Description:
 *   This program writes and reads an int array to stdout and a BINARY file
 *****************************************************************************/
#include <stdio.h>

int main( void )
{
    FILE * out_file = NULL;
    int  inx = 0;
    int  out_data[5] = { 1, 2, 3, 4, 5 };
    int in_data[5];
    /*
     * write out_data to standard out as ASCII
     */
    for ( inx = 0; inx < 5; inx ++ )
      fprintf( stdout, "out_data ==>%d\n", out_data[inx] );
    /*
     * open the file in write mode
     */
    if ( (out_file = fopen( "mydata.bin", "wb" )) == NULL )
    {
      fprintf( stderr, "Could not open mydata.bin" );
    }
    else
    {
    /*
     * write out_data to the file as BINARY
     */
      fwrite( out_data, sizeof( int ), 5, out_file );
    /*
     * OR, write each item individually
     *  for ( inx = 0; inx < 5; inx++ )
     *    fwrite( &out_data[inx], sizeof( int ), 1, out_file );
     */
      fclose( out_file );
      out_file = NULL;
      if ( (out_file = fopen( "mydata.bin", "rb" )) == NULL )
      {
        fprintf( stderr, "Could not open mydata.bin" );
      }
      else
      {
         fread( in_data, sizeof( int ), 5, out_file  );
         for ( inx = 0; inx < 5; inx ++ )
           fprintf( stdout, "in_data ==>%d\n", in_data[inx] );
      }
    }
}

