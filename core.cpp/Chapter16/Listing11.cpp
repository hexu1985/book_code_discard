// Listing 16.11	Using a Matrix class with the overloaded function call operator.

#include <iostream>   
#include <iomanip>
using namespace std;

class Matrix {
  int *cells;                 // heap array to house the matrix
  int size;                   // number of rows and of columns
  int* make(int size)         // private allocator function 
  { int* p = new int [size * size]; // total number of elements
    if (p == NULL) { cout << "Matrix too big\n";  exit(0); }
    return p; }               // return pointer to heap storage
public:
  Matrix (int sz) : size(sz)  // conversion constructor
  { cells = make(size); }     // heap memory is not initialized
  Matrix (const Matrix& m) : size(m.size)
  { cells = make(size); }     // copy constructor: for safety
  Matrix& operator = (const Matrix& m);  // assignment operator
  int getSize() const                    // size of the side
  { return size; }
  int& operator () (int r, int c) const; // access or modify 
  ~Matrix() { delete [] cells; } // destructor
  } ;

Matrix& Matrix::operator = (const Matrix& m)  // assignment
{ if (this == &m) return *this; // no work if self-assignment
  delete [ ] cells;             // return existing memory
  cells = make(m.size);         // allocate/set new memory
  size = m.size;                // set the matrix size
  for (int i=0;  i<size*size;  i++)  // copy data
	  cells[i] = m.cells[i];
  return *this; }               // to support chain assignment

int& Matrix::operator () (int r, int c) const 
  {  if (r<0 || c<0 || r>=size || c>=size)  // check validity
        return cells[size*size-1];  // return last matrix cell
      return cells[r*size + c]; }   // return requested cell

void printMatrix(const Matrix& m)  // client function
{ int size = m.getSize();
  for (int i=0; i < size; i++)     // go over each row
  { for (int j=0;  j < size;  j++) // and each column
      cout << setw(4) << m(i,j);   // print the cell
    cout << endl; }                // end the current row
  cout << endl; }                  // end the matrix

int main()
{ cout << endl << endl;
  int i, j, n = 5;  Matrix m1(n);   // Matrix object
  for (i=0; i < n; i++)
    for (j=0;  j < n;  j++)         // initialize cells
       m1(i,j) = (i+1) * (j+1);     // m1[i][j] = (i+1)*(j+1);
  printMatrix(m1);                  // print matrix state
  for (i=0; i < n; i++)             // put 0's on main diagonal
     m1(i,i) = 0;                   // m1[i][i] = 0
  printMatrix(m1);                  // print new state
  cout << "m[10][10] = " << m1(10,10) << endl;  // out of bounds
  return 0;
  }
