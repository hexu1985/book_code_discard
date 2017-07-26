
#include <iostream>
#include "ilist.h"

using std::cout;

int main()
{
    ilist mylist;
    
    for (int ix = 0; ix < 10; ++ix) {
        mylist.insert_front(ix);
    }
    
    mylist.display();
    
    cout << "\n" << "reverse the list\n";
    mylist.reverse2();
    mylist.display();
    
    ilist mylist_too;
    mylist_too.insert_end(0);
    mylist_too.insert_end(1);
    mylist_too.insert_end(1);
    mylist_too.insert_end(2);
    mylist_too.insert_end(3);
    mylist_too.insert_end(5);
    
    cout << "\n" << "mylist_too\n";
    mylist_too.display();
    
    mylist.concat(mylist_too);
    cout << "\n" << "mylist after concat with mylist_too:\n";
    mylist.display();
    
    ilist mylist_null;
    mylist_null.reverse2();
    mylist_null.display();
    
    return 0;
}
