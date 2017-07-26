// Listing 6.11. Using a dynamic array to accommodate infinite input string

 #include <iostream>
 using namespace std;
 
 int main(void)
  { 
    const int LEN = 8; int len=1; // short array for debugging
    char buf[LEN], *data = 0;     // init to zero for first pass
    cout << " Type text, press Enter: \n";
    do { 
     cin.get(buf,LEN);            // data goes into a stack array
     len += strlen(buf);     // total length of old and new data
     char *temp = new char[len]; // request new heap array for data
     if (temp == 0)             // test for allocation success
       { cout << " Out of memory: program terminated\n";
 	 return 0; }                // no luck, give up
     if (data == 0)
         strcpy(temp,buf);        // copy data from input buffer
     else
     { 
       strcpy(temp,data); strcat(temp,buf); } // copy existing data
       delete [] data;               // delete existing array 
       data = temp;               // point to the new array
       cout << " Total: " << len << " added: " << buf << endl; 
       cout << " Dynamic buffer: " << data << endl; // debug  
 
    char ch = cin.peek();         // what is left in the buffer?
    if (ch == '\n')               // quit if it is new line 
     { ch = cin.get(); break; }
    } while (true);         // or keep going until EOF
    cout << "\n You entered the following line: \n\n";
    cout << data << endl;         // same syntax as for arrays
    delete [] data;
     return 0;
  }

