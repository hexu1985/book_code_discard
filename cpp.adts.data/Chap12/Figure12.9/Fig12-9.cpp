#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*-------------------------------------------------------------------------
  Program to validate computer user-ids and passwords.  A list of valid
  ids and passwords is read from UsersFile and is stored in a BST.  When
  user-ids and passwords are entered during execution, this BST is 
  searched to determine whether they are legal.
 
   Input (file):     UserInfo records for valid users
   Input (keyboard): Ids and passwords of users logging in
   Output (screen):  Messages indicating whether user-ids and passwords
                       are valid
 -------------------------------------------------------------------------*/

//----- Class containing user information -----//
//      with >>, ==, and < operators
class UserInfo
{
 public: 
  // ***** Function Members and Friends ***** //
  //--- id accessor
  string id() const { return myId; }

  //--- input function
  void read(istream & in)
  {
    in >> myId >> myPassword;
  }

  //--- equals operator
  bool operator==(const UserInfo & user) const
  { return myId == user.myId &&
           myPassword == user.myPassword; }

  //--- less-than operator
  bool operator<(const UserInfo & user) const
  { return myId < user.myId ||
           myId == user.myId && myPassword < user.myPassword; }

  private: 
  // ***** Data Members ***** //
  string myId,
         myPassword;
};

//--- Definition of input operator
istream & operator>>(istream & in, UserInfo & user)
{
  user.read(in);
}


#include "BST.h"

int main()
{
   // Open stream to file of legal user-ids and password
   string userFile;
   cout << "Enter name of user-info file: ";
   getline(cin, userFile);
   ifstream inStream(userFile.data());
   if (!inStream.is_open())
   {
      cerr << "Cannot open " << userFile << "\n";
      exit(1);
   }

   // Build the BST of user records
   BST<UserInfo> userTree;   // BST of user records
   UserInfo user;            // a user record
   for(;;)
   {
      inStream >> user;
      if (inStream.eof()) break;

      userTree.insert(user);
   }

   // Validate logins
   cout << "Enter Q Q to stop processing.\n";
   for (;;)
   {
      cout << "\nUser id & password: ";
      cin >> user;
      if (user.id() == "Q") break;
      if (userTree.search(user))
         cout << "Valid user\n";
      else
         cout << "Not a valid user\n";
   }
}
