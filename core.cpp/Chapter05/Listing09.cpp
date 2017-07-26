// Listing 5.9. Using a two-dimensional array of characters for search

#include <iostream>  
#include <cstring>
using namespace std;

#define  NUM  7 // do we expect to change the week length soon?

int main(void)
{ 
  int i;  char day[10]; 
  char days[NUM][10] = { "Sunday","Monday","Tuesday",
      "Wednesday","Thursday","friday","Saturday" };
  do {                       // do until the user enters "end"
   cout << "Enter day of the week or 'end' to finish: ";
   cin.get(day,10); cin.ignore(2000,'\n'); // this is prudent
   cout << "Your input: " << day << endl;
   if (strcmp(day,"end")==0)  break;
   for (i = 0;  i < NUM;  i++)
     if (strcmp(day,days[i])==0) break; // stop search if found
    if (i == NUM)          // check for what reason we got here
     cout << "Input \"" << day << "\" is incorrect\n";
   else
     cout << day << " is day no. " << i+1 << endl;
   } while (1==1);         // go on until the user enters "end"
   cout << "Thank you for using this program" << endl;
   return 0;
  }
