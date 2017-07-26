// Listing 2-12. Corrected C++ program with prototypes preceding the function calls

const double PI = 3.1415926;

void displayInitialGreeting();                         // function prototypes
double computeSquare(double x, double y);
void displayResults(double y);

int main(void)  
{ 
  double x=PI, y=1; // 
  displayInitialGreeting();                            // function calls
  y = computeSquare(x,y);
  displayResults(y);
  return 0;
}                // end of the function block 
