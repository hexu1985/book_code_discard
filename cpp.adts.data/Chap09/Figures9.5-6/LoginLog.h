/*-- LoginLog.h ------------------------------------------------------------
  This header file defines a LoginLog class template for modeling a
  computer log of user information recorded during logins over some 
  period of time.  The type parameter Info represents the login
  information recorded for a user.

  Basic operations:
    build:    Builds the log of information for distinct users
    search:   Searches the computer log for a particular user
    display:  Displays the contents of the log
    
   Note:  >>, <<, and == must be defined for type Info.
--------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

#ifndef LOGIN_LOG
#define LOGIN_LOG

template <typename Info>
class LoginLog
{
 public:
 /***** Function Members *****/
 /***** Constructor *****/
  //-- Let vector's constructor do the work 
 
  void build(string fileName);
  /*-----------------------------------------------------------------------
    Build the log.

    Precondition:  None.
    Postcondition: Log has been built using input via a stream connected 
        to fileName.
   -----------------------------------------------------------------------*/

  int search(Info item) const;
  /*-----------------------------------------------------------------------
    Search user log for a given Info object.

    Precondition:  None.
    Postcondition: The index in myUserLog where item is found is returned,
        myUserLog.size() if not found.
  ------------------------------------------------------------------------*/

   void display(ostream & out) const;
  /*-----------------------------------------------------------------------
    Output the log.

    Precondition:  ostream out is a reference parameter.
    Postcondition: Log has been output to out.
  ------------------------------------------------------------------------*/

 private:
   vector<Info> myUserLog;
};

//--- Definition of build()
template <typename Info>
void LoginLog<Info>::build(string fileName)
{
   ifstream fin(fileName.data());    // open input stream to file
   assert (fin.is_open());           // check if successful
   
   Info userInfo;
   for(;;)
   {
      fin >> userInfo;
      if ( fin.eof() ) break;

      int pos = search(userInfo);
      if (pos == myUserLog.size())    // new user
         myUserLog.push_back(userInfo);
   }
}

//--- Definition of search
template <typename Info>
int LoginLog<Info>::search(Info item) const
{
   int i;
   for (i = 0; i < myUserLog.size(); i++)
      if (item == myUserLog[i])
         break;
   return i;
}

//--- Definition of display()
template <typename Info>
inline void LoginLog<Info>::display(ostream & out) const
{
   for (int i = 0; i < myUserLog.size(); i++)
      out << myUserLog[i] << endl;
}

#endif
