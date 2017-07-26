// Listing 6.13. Using a linked list of heap nodes

#include <iostream>
#include <iomanip>
using namespace std;

typedef double Item;

struct Node {
  Item item;
  Node* next; } ;

int main ()
{  int count = 0;             // count of amounts
   Node *data=0, *last;  // pointers to start and end of list

do {                          // do until EOF causes failure
  double amount;              // local variable for input
  cout << " Enter amount (or 0 to finish): ";
  if (amount == 0) break;
  cin >> amount;             // get next double from user
  if (amount==0) break;        // stop input on no more data
   Node* q = new Node;        // create new node on the heap
   if (q == 0)                // test for success of request
     { cout << "Out of heap memory" << endl;       break; } 
   q->item = amount;          // fill node with program data
   q->next = NULL;            // sentinel value for list end

   (data == 0 ? data : last->next) = q;
 last = q;                  // last=last->next; is ok, too
   count++;                   // increment count
   } while (true);
cout << "\nTotal of " << count << " values are loaded\n";
  if (count == 0) return 0;     // no output if no file input
  cout << "\nNumber  Amount  Subtotal\n\n";  // print header
  cout.setf(ios::fixed);      // fixed format for double
  cout.precision(2);          // digits after decimal point
  double total = 0;           // total for input amounts
  Node *q = data;             // start at start of the list
  for (int i = 0;  i < count;  i++)  // go over list data 
   { total += q->item;                // accumulate total
     cout.width(3); cout << i+1;      // transaction number
     cout.width(10); cout << q->item; // transaction value
     cout.width(11); cout << total << endl; // running total
     q = q->next; } // idiom to pointing pointer to next node
  Node *p = data, *r = data;    // initialize traversing pointers
  while (p != NULL)           // go on until it runs off the list
   { p = p->next;       // prevent next node from hanging
     delete r;  r = p; }   // delete node, catch up with next
  return 0;
 }

