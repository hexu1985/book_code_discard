
int pow( int val, int exp )
{
	int res;
	for ( res = 1; exp > 0; --exp )
		res = res * val;
	return res;
}
