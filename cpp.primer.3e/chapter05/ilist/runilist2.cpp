
#include <iostream>
#include "ilist.h"

using std::cout;

int main()
{
    ilist mylist;
    cout << "\n---------------------------------------------------\n"
         << "test #1: items at end\n"
         << "\n---------------------------------------------------\n";
         
    mylist.insert_front(1);
    mylist.insert_front(1);
    mylist.insert_front(1);
    mylist.insert_front(2);
    mylist.insert_front(3);
    mylist.insert_front(4);
    
    mylist.display();
    
    int elem_cnt = mylist.remove(1);
    cout << "\n" << "Removed " << elem_cnt << " of the value 1\n";
    mylist.display();
    
    mylist.remove_all();
    
    cout << "\n---------------------------------------------------\n"
         << "test #2: items at front\n"
         << "\n---------------------------------------------------\n";
    
    mylist.insert_front(1);
    mylist.insert_front(1);
    mylist.insert_front(1);
    mylist.display();
    
    elem_cnt = mylist.remove(1);
    cout << "\n" << "Removed " << elem_cnt << " of the value 1\n";
    mylist.display();
    
    mylist.remove_all();
    
    cout << "\n---------------------------------------------------\n"
         << "test #3: no items present\n"
         << "\n---------------------------------------------------\n";
    
    mylist.insert_front(0);
    mylist.insert_front(2);
    mylist.insert_front(4);
    mylist.display();
    
    elem_cnt = mylist.remove(1);
    cout << "\n" << "Removed " << elem_cnt << " of value 1\n";
    mylist.display();
    
    mylist.remove_all();
    
    cout << "\n---------------------------------------------------\n"
         << "test #4: items at front and end\n"
         << "\n---------------------------------------------------\n";
    mylist.insert_front(1);
    mylist.insert_front(1);
    mylist.insert_front(1);
    mylist.insert_front(0);
    mylist.insert_front(2);
    mylist.insert_front(4);
    mylist.insert_front(1);
    mylist.insert_front(1);
    mylist.insert_front(1);
    
    mylist.display();
    elem_cnt = mylist.remove(1);
    cout << "\n" << "Removed " << elem_cnt << " of the value 1\n";
    mylist.display();
    
    return 0;
}
