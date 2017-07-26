/* filerw.cpp */
/* on page 17 of C++ Primer 3e */

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	using std::ofstream;
	using std::ifstream;
	using std::cerr;
	using std::string;
	
	ofstream outfile( "out_file" );
	ifstream infile( "in_file" );
	if ( ! infile ) {
		cerr << "error: unable to open input file!\n";
		return -1;
	}
	if ( ! outfile ) {
		cerr << "error: unable to open output file!\n";
		return -2;
	}
	string word;
	while ( infile >> word )
		outfile << word << ' ';
	return 0;
}
