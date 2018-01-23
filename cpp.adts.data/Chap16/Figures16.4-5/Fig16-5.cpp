/*-------------------------------------------------------------------------
  Program to determine if a graph is connected. If the graph is not
  connected, a list of unreachable vertices from the start vertex is
  provided to the user.
  ------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "Graph.h"

int main()
{
  int numVertices,         // number of vertices in the graph
      numEdges;            //   "     "  edges   "   "    "

  cout << "Enter number of vertices and number of edges in graph: ";
  cin >> numVertices >> numEdges;
  Graph<char> g;
  g.read(cin, numVertices, numEdges);

  cout << "Graph is ";
  if (g.isConnected())
    cout << "connected.\n";
  else
  {
    cout << "not connected.\n"
            "Would you like to see which vertices are not\n"
            "reachable from vertex 1 (" 
         << g.data(1) << ") -- (Y or N)? ";
    char response;
    cin >> response;
    if (response == 'y' || response == 'Y')
    {
      cout << "They are the following: \n";
      vector<bool> unreachable(numVertices + 1, true);
      g.depthFirstSearch(1, unreachable);
      for (int i = 1; i < unreachable.size(); i++)
        if (unreachable[i])
          cout << "Vertex " << i << " (" << g.data(i) << ")\n";
    }
    cout << endl;
  }
}
