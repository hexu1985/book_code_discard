// Listing 2-14. Your first C++ class that combines data and functions

#include <iostream>
using namespace std;

class TimeOfDay {                                 // keyword class is used
    private:                                      // keyword private makes data hidden
       int hours, minutes;                  // private data is not accessible from outside
    public:                                       // keyword public makes functions visible
        void setTime(int hrs, int min)
         { hours = hrs;  minutes = min; }          // first member function: setTime()
        void displayMilitaryTime(void)
         { cout << hours << ":" << minutes; }  // second function: displayMili-taryTime()
        void displayTime(void)
         { if (hours > 12)                         // third member function: displayTime()
              cout << hours-12<<":"<<minutes<<"P.M.";
            else
              cout << hours <<":"<<minutes<<"A.M."; }
     } ;
