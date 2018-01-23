#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

//--- Overload output operator for list<T>
template <typename T>
ostream & operator<<(ostream & out, const list<T> & aList)
{
   for (list<T>::const_iterator it = aList.begin(); it != aList.end(); it++)
      out << *it << " ";
   return out;
}

int main()
{
   // Constructors
   //=============
   list<int> la, lb(4, 111), lc(6);
   int array[] = {2, 22, 222,2222};
   list<int> ld(array, array + 4);

   cout << "la: " << la << " -- size = " << la.size() << endl;
   cout << "lb: " << lb << " -- size = " << lb.size() << endl;
   cout << "lc: " << lc << " -- size = " << lc.size() << endl;
   cout << "ld: " << ld << " -- size = " << ld.size() << endl;

   // Assignment
   //===========
   cout << "\nAssignments la = ld and lc = ld:" << endl;
   la = ld;
   lc = ld;
   cout << "la = " << la << " -- size = " << la.size() << endl;
   cout << "lc = " << lc << " -- size = " << lc.size() << endl;
 
   // Ways to insert into a list
   //===========================
   cout << "\nInserts in lb:\n";
   list<int>::iterator i;
   i = lb.begin();
   i++; i++;
   lb.insert(i, 66666);
   cout << lb << endl;
   lb.insert(i,3, 555);
   cout << lb << endl;
   lb.insert(i, array, array + 3);
   cout << lb << endl;
   lb.push_back(888);
   lb.push_front(111);
   cout << lb << endl;
  
   // Ways to delete from a list
   //===========================
   cout << "\nErases in lb:\n";
   i = find(lb.begin(), lb.end(), 66666);  // find is an algorithm
   if (i != lb.end())
   {
      cout << "66666 found -- will erase it\n";
      lb.erase(i);
   }
   else
      cout << "66666 not found\n";
   cout << lb << endl;
   i = lb.begin(); i++;
   list<int>::iterator j = lb.end();
   --j; --j; i = --j; i --; i--;
   lb.erase(i,j);
   cout << lb << endl;
   lb.pop_back();
   lb.pop_front();
   cout << lb << endl;

   // Reversing a list
   //=================
   cout << "\nReverse ld:\n";
   ld.reverse();
   cout << ld << endl;
 
   // Sorting a list
   //===============
   cout << "\nSort lb and ld:\n";
   lb.sort();
   ld.sort();
   cout << "lb: " << lb << "\nld: " << ld << endl;
 
   // Merging two lists
   //==================
   cout << "\nMerge lb and ld:\n";
   lb.merge(ld);
   cout << "lb: " << lb << endl;
   cout << "ld: " << ld << endl;

   // Splicing a list into another list
   //==================================
   cout << "\nSplice lc into la at second position:\n";
   i=la.begin(); i++;
   la.splice(i, lc);
   cout << "la: " << la << endl;
   cout << "lc: " << lc << endl;

   // Global removal of a value
   //==========================
   cout << "\nRemove 22s from la:\n";
   la.remove(22);
   cout << la << endl;

   // Eliminating duplicates
   //=======================
   cout << "\nUnique applied to lb:\n";
   lb.unique();
   cout << lb << endl;
}
