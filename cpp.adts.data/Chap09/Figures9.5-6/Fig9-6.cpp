/*---------------------------------------------------------------------
  Program to determine which users were logged into a computer
  system for a given period of time.
  
  Input (keyboard): Name of the user-id file
  Input (file):     User ids
  Output (screen):  A list of distinct user-ids
 --------------------------------------------------------------------*/
 
#include <iostream>
#include <string>
using namespace std;

#include "LoginLog.h"

int main()
{
   // Get name of log file
   string userInfoFile;         // log file of user-ids
   cout << "Enter name of login-info file: ";
   getline(cin, userInfoFile);

   // Read the log from the file
   LoginLog<string> userIdLog;
   userIdLog.build(userInfoFile);

   // Display the log
   cout << "\nList of distinct user-ids who logged in:\n";
   userIdLog.display(cout);
}
