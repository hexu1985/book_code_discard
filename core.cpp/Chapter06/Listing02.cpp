// Listing 6.2. Demonstration of nesting scopes and name overriding

#include <iostream>
using namespace std;

 struct Account {
   long num;     
   double bal; } ;   
 
 const int MAX = 5;            // maximum size of the data set
 int count = 0;                // number of elements in data set
 Account a[MAX];               // global data to be processed

 void printAccounts()
 { for (int i = 0;  i < count;  i++)        // global count
    { double count = a[i].bal;              // local count
      cout << a[i].num << "   " << count << endl; } }
 
 int main()
 { 
   typedef int Index;
   long num[MAX] = { 800123456, 800123123, 800123333, -1 } ;
   long number = 800123123;  double total = 0;  // outer scope
   while (true)                  // break it in the sentinel
   { double amounts[MAX] = { 1200, 1500, 1800 } ; // data to load
     if (num[count] == -1) break;  // sentinel is found
     double number = amounts[count]; // number hides outer number
     a[count].num = num[count];                   // loading data
     a[count].bal = number;
     count++; } 
     cout << "  Data is loaded\n\n";
     printAccounts();
     for (Index i = 0; i < count; i++)      // global count
      { double count = a[i].bal; 
        total += count;                     // local count
        if (i == ::count - 1)               // global count
           cout << "Total of balances $" << total << endl; }
	 for (Index j = 0; j < count; j++)
       if (a[j].num == number)        // outer number, global array
         cout <<"Account "<< number <<" has: $" << a[j].bal << endl;
     return 0;
  }
