
#include <iostream>

using std::cout;
using std::endl;

void print_array(int *begin, int *end);

void quitsort(int *begin, int *end)
{
	if (begin >= end)
		return;
	
	int *low = begin + 1;
	int *high = end - 1;	
	for ( ; ; ) {
		while (*low < *begin && low < end)
			low++;
		while (*begin < *high && high > begin)
			high--;
		if (low < high) {
			int tmp;
			tmp = *low;
			*low = *high;
			*high = tmp;
		} else
			break;
	}
	
	{
		int tmp;
		tmp = *begin;
		*begin = *high;
		*high = tmp;
	}
	quitsort(begin, high);
	quitsort(high + 1, end);
}

void print_array(int *begin, int *end)
{
	cout << "< ";
	for (int *index = begin; index < end; index++)
		cout << *index << " ";
	cout << " >" << endl;
}

int main()
{
	int array[] = {1, 3, 8, 23, 4, 29, 37, 123, 82, 13, 1, 34, 45};
	
	cout << "快速排序前，array:" << endl;
	print_array(array, array + sizeof (array) / sizeof (array[0]));
	
	quitsort(array, array + sizeof(array) / sizeof (array[0]));
	cout << "快速排序后，array:" << endl;
	print_array(array, array + sizeof (array) / sizeof (array[0]));
	
	return 0;
}
