// Listing 6.15. Using a linked list of heap nodes for data read from a disk file

#include <iostream> 
#include <iomanip>
#include <fstream>   // for ifstream class

using namespace std;

typedef double Item;
  
struct Node {
  Item item;
  Node* next; } ;
    
int main ()
{ 
   int count = 0;                 // count of amounts
   Node *data=0, *last;  // pointers to start and end of list
   ifstream f("amounts.dat");    // file to read data from
   if (f.fail())
   { cout << "Cannot open file" << endl; return 0; }
do {                             // do until EOF causes failure
  double amount;                 // local variable for input
//  cout << " Enter amount (or 0 to finish): ";
//  cin >> amount;           // get next double from user
//  if (amount == 0) break;
  f >> amount;                   // get next double from file
  if (f.eof()) break;            // stop input if no more data
   Node* q = new Node;           // create new node on the heap
   if (q == 0)                   // test for success of request
     { cout << "Out of heap memory" << endl;  break; } 
   q->item = amount;  q->next = NULL;   // fill node with data
   (data == 0 ? data : last->next) = q;
   last = q;                     // last=last->next; is ok, too
   count++;                      // increment count
   } while (true);
  cout << "\nTotal of " << count << " values are loaded\n";
  if (count == 0) return 0;      // no output if no file input
  cout << "\nNumber  Amount  Subtotal\n\n";  // print table header
  cout.setf(ios::fixed);         // fixed format for double
  cout.precision(2);             // digits after decimal point
  double total = 0;              // total for input amounts
  int i = 0;
  for (Node *q = data;  q != NULL;  q = q->next)  // OK
   { total += q->item;           // accumulate total
     cout << setw(3) << ++i;           // transaction number
     cout << setw(10) << q->item;      // transaction value
     cout << setw(11) << total << endl;  // running total
    }
  Node *p = data, *r = data;
  while (p != 0)
  { p = p->next;
    delete r;  r = p; }
  return 0;
}

