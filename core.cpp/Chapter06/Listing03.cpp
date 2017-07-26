// Listing 6.3. Communicating with another file through external declara-tions (Part 1 of 2)

#include <iostream>
using namespace std;
 
 struct Account {                // global type definition
   long num;     
   double bal; } ; 
   
 extern void printAverage(double total); // defined elsewhere
 
 const int MAX = 5;
 Account a[MAX];               // global data to be processed

 int count = 0;              // number of elements in data set
 char caption[] = "Average balance is $";   // caption to print
 
 long num[MAX] = { 800123456, 800123123, 800123333, -1 } ;
 double amounts[MAX] = { 1200, 1500, 1800 } ;  // data set to load
   
 void printAccounts()
 { for (int i = 0;  i < count;  i++)        // global count
    { cout << a[i].num << "   " << a[i].bal << endl; } }
 
 int main()
 { 
   double total = 0;
   while (true)                      // break on sentinel
   { if (num[count] == -1) break;
     a[count].num = num[count];   // global a[], num[], amounts[]
     a[count].bal = amounts[count++]; }   // load data
   cout << "  Data is loaded\n\n";
   printAccounts();                    // local function
   cout << "\n  Data is processed\n\n"; 
   for (int i = 0; i < count; i++)
     { total += a[i].bal; }
   printAverage(total);                // global in another file
   return 0;
  }
