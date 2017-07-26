#include <stdio.h>
#include <stdlib.h>

typedef struct  
{
	unsigned long id;
	int data;
} record;

int main()
{
	int id_cmp( const void *s1, const void *s2 );

	record recordset[] = { {3, 5}, {5, -5}, {4, 10}, {2, 2}, {1, -17} };
	record querykey;
	record *found = NULL;
	int recordcount = sizeof(recordset) / sizeof(record);

	printf( "Query record number: " );
	scanf( "%lu", &querykey.id );

	printf( "\nRecords before sorting:\n\n"
			"%8s %8s %8s\n", "Index", "ID", "Data" );

	int i = 0;
	for ( i = 0; i < recordcount; i++ )
		printf( "%8d %8u %8d\n", i, recordset[i].id, recordset[i].data );

	qsort( recordset, recordcount, sizeof( record ), id_cmp );

	printf( "\nRecords after sorting:\n\n"
			"%8s %8s %8s", "Index", "ID", "Data" );
	for ( i = 0; i < recordcount; i++ )
		printf( "%8d %8u %8d\n", i, recordset[i].id, recordset[i].data );
	
	found = (record *)bsearch( &querykey, recordset, recordcount, 
							   sizeof(record), id_cmp );

	if ( found == NULL )
		printf( "No record with the ID %lu found.\n", querykey.id );
	else
		printf( "The data value in record %lu is %d.\n", 
				querykey.id, found->data );
}

int id_cmp( const void *s1, const void *s2 )
{
	record *p1 = (record *)s1;
	record *p2 = (record *)s2;
	if ( p1->id < p2->id )
		return -1;
	else if ( p1->id == p2->id )
		return 0;
	else
		return 1;
}