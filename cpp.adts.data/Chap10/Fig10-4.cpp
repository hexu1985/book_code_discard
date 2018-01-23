/*-------------------------------------------------------------------------
   Program to solve the Towers of Hanoi puzzle recursively.

   Input:  numDisks, the number of disks to be moved
   Output: A sequence of moves that solve the puzzle
 -------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

void move(unsigned n, unsigned & moveNumber,
          char source, char destination, char spare);

int main()
{
   const char PEG1 = 'A',           // the three pegs
              PEG2 = 'B',
              PEG3 = 'C';
   unsigned moveNumber = 0;         // counts the moves

   cout << "This program solves the Hanoi Towers puzzle.\n\n";
   cout << "Enter the number of disks: ";
   int numDisks;                     // the number of disks to be moved
   cin >> numDisks;
   cout << endl;

   move(numDisks, moveNumber, PEG1, PEG3, PEG2); // the solution
}

void move(unsigned n, unsigned & moveNumber,
          char source, char destination, char spare)
/*-------------------------------------------------------------------------
  Recursive function to solve the Towers of Hanoi puzzle with n disks.

  Precondition:  None.
  Postcondition: A message describing the move is output to cout.
 ------------------------------------------------------------------------*/
{
  if (n == 1)                         // anchor
  {
    moveNumber++;
    cout << setw(3) << moveNumber 
         <<  ". Move the top disk from " << source  
         << " to " << destination << endl;
  }
  else
  {                                   // inductive case
    move(n-1, moveNumber, source, spare, destination);
    move(1, moveNumber, source, destination, spare);
    move(n-1, moveNumber, spare, destination, source);
  }
}
