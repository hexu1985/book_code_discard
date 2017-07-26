// Listing 6.12. Using a dynamic array to read an arbitrary set of lines 

 #include <iostream>
 using namespace std;
 
 int main(void)
  { 
    const int LEN = 8;    char buf[LEN];
    int cnt = 0;
 
    cout << "Enter data (or press Return to end): \n";
 do {                  // start of outer loop for input lines
    char *data = new char[1];  data[0] = 0;    // initially, it is empty
    int len = 0;                           // initial size is zero
    do {               // start of inner loop for line segments
     cin.get(buf,LEN);               // get next line segment
     len += strlen(buf);            // update total string length
 
     char *temp = new char[len+1];
       strcpy(temp,data);  strcat(temp,buf); 
       delete data;
       data = temp;                 // expand the long line
     cout <<"Allocated " << len+1 <<": " <<data <<endl;
     char ch = cin.peek();        // what is left in the buffer? 
     if (ch == '\n' || ch == EOF)  // quit if if new line
     { ch = cin.get(); break; }    // but first remove it from input  break; }
	 } while (true);
    
    if (len == 0) break; // end on empty string
 
    cout << " line " << ++cnt << ": " << data << endl;
    delete [ ] data;
     } while (true);     // continue until break on empty line
 
     return 0;
  }
