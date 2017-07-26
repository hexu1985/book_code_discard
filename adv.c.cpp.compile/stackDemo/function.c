int 
sum_of_integer_squares_between(unsigned int lower, 
                               unsigned int upper)
{
	// 
	// Sum of squares of first n integers equals 
     // n(n+1)(2n+1)/6;
	//
	int nUpperSum = upper*(upper + 1)*(2*upper + 1)/6;
	int nLowerSum = lower*(lower + 1)*(2*lower + 1)/6;
	return nUpperSum - nLowerSum;
}
