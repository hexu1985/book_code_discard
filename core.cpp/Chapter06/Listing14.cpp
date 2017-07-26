// Listing 6.14. Using a dynamic array to read an arbitrary set of lines and write it to a disk file

#include <iostream>  
#include <fstream>   // for ifstream, ofstream objects
using namespace std;

int main(void)
 { 
   const int LEN = 8;  char buf[LEN];  // short buffer for input
   int cnt = 0;                        // line count
   ofstream f("data.out");        // new: output file object
   cout << "Enter data (or press Return to end):\n";
do {                  // start of outer loop for input lines
   int len = 0;                    // initial length of data
   char *data = new char[1]; data[0] = '\0';
   do {               // start of inner loop for line segments
	cin.get(buf,LEN);               // get next line segment
    len += strlen(buf);             // update total string length
    char *temp = new char[len+1];
    strcpy(temp,data);  strcat(temp,buf); 
    delete data;  data = temp;      // expand the long line
    int ch = cin.peek();         // what is left in the buffer?
    if (ch == '\n' || ch == EOF)  // quit if it is new line or EOF
	 { ch = cin.get(); break; } // but first remove it from input
   } while (true);               // continue until break on new line
   if (len == 0) break;          // quit if the input line is empty
   cout << " line " << ++cnt << ": " << data << endl;
   f << data << endl;            // save data to the file
   delete [] data;                // avoid memory leak
    } while (true);         // continue until break on empty line
   cout << " Data is saved in file data.out" << endl;
   return 0;
   }

