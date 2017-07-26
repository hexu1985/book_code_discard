/* FGETPOS.C: This program opens a file and reads
 * bytes at several different locations.
 */

#include <stdio.h>

void main( void )
{
   FILE   *stream;
   fpos_t pos;
   char   buffer[20];
   char	  *ptest = NULL;

   if( (stream = fopen( "fgetpos.c", "rb" )) == NULL )
      printf( "Trouble opening file\n" );
   else
   {
      /* Read some data and then check the position. */
      if ( fread( buffer, sizeof( char ), 10, stream ) != 10 )
		 printf( "read file failure!\n" );
	  else
		 printf( "10 bytes at begin: %.10s\n", buffer );

      if( fgetpos( stream, &pos ) != 0 )
         perror( "fgetpos error" );
      else
      {
		 if ( fread( buffer, sizeof( char ), 10, stream ) != 10 )
			 printf( "read file failure!\n" );
		 else
			 printf( "10 bytes at byte %ld: %.10s\n", (int)pos, buffer );
      }

   /* Set a new position and read more data */
   pos = 140;
   if( fsetpos( stream, &pos ) != 0 )
      perror( "fsetpos error" );

   if ( fread( buffer, sizeof( char ), 10, stream ) != 10 )
	   printf( "read file failure!\n" );
   else
	   printf( "10 bytes at byte %ld: %.10s\n", (int)pos, buffer );
   fclose( stream );
   }

   printf( "%.10s\n", ptest );
}
