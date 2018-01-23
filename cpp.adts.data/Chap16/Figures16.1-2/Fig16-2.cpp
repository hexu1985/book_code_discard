/*-------------------------------------------------------------------------
  Program to find the most direct route in an airline network from a given
  start city to a given destination city.  A digraph represented by its
  adjacency-list implementation is used for the network, and the
  information needed to construct it is read from networkFile.
 -------------------------------------------------------------------------*/
 
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "Digraph.h"

int main()
{
  cout << "Enter name of network file: ";
  string networkFile;
  cin >> networkFile;
  ifstream inFile(networkFile.data());
  if (!inFile.is_open())
  {
    cerr << "*** Cannot open " << networkFile << " ***\n";
    exit(-1);
  }

  Digraph<string> d;
  d.read(inFile);
  cout << "The Digraph's ";
  d.display(cout);
  cout << endl;
  
  int start, destination;
  char response;
  do
  {
    cout << "Number of start city? ";
    cin >> start;
    cout << "Number of destination? ";
    cin >> destination;

    vector<int> path = d.shortestPath(start, destination);
    cout << "Shortest path is:\n";
    for (int k = 0; k < path.size(); k++)
    {
      cout << setw(3) << path[k] << ' ' << d.data(path[k]) << endl;
      cout << "      |\n"
              "      v\n";
    }
    cout << setw(3) << destination << ' ' << d.data(destination) << endl;
    cout << "\nMore (Y or N)?";
    cin >> response;
  }
  while (response == 'y' || response == 'Y');
}
