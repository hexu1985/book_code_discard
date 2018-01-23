/*--- Digraph.h ------------------------------------------------------------
                Header file for Digraph Class Template
 -------------------------------------------------------------------------*/

#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>

template <typename DataType>
class Digraph
{
 public:
  /***** Function Members *****/
  DataType data(int k) const;
  /*-----------------------------------------------------------------------
    Retrieve data value in a given vertex.

    Precondition:  k is the number of a vertex.
    Postcondition: Data value stored in vertex k is returned.
   -----------------------------------------------------------------------*/

  void read(ifstream & inStream);
  /*-----------------------------------------------------------------------
    Input operation.

    Precondition:  ifstream inStream is open.  The lines in the file to
        which it is connected are organized so that the data item in a
        vertex is on one line and on the next line is the number of 
        vertices adjacent to it followed by a list of these vertices.
    Postcondition: The adjacency list representation of this digraph 
         has been stored in myAdjacencyLists.
   -----------------------------------------------------------------------*/

 void display(ostream & out);
  /*-----------------------------------------------------------------------
    Output operation.

    Precondition:  ostream out is open.
    Postcondition: Each vertex and its adjacency list have
        been output to out.
   -----------------------------------------------------------------------*/

  void depthFirstSearch(int start);
  /*-----------------------------------------------------------------------
    Depth first search of digraph via depthFirstSearchAux(), starting
    at vertex start.

    Precondition:  start is a vertex.
    Postcondition: Digraph has been depth-first searched from start.
   -----------------------------------------------------------------------*/

  vector<int> shortestPath(int start, int destination);
  /*-----------------------------------------------------------------------
    Find a shortest path in the digraph from vertex start to vertex
    destination.

    Precondition:  start and destination are vertices.
    Postcondition: A vector of vertices along the shortest path from
        start to destination is returned.
   -----------------------------------------------------------------------*/

 private:
  /***** "Head nodes" of adjacency lists *****/
   class VertexInfo
   {
    public: 
     DataType data;
     list<int> adjacencyList;
   }; // end of VertexInfo class

  /***** Data Member *****/
   vector<VertexInfo> myAdjacencyLists;

  /***** Private Function Member *****/
  void depthFirstSearchAux(int start, vector<bool> & unvisited);
  /*-----------------------------------------------------------------------
    Recursive depth first search of digraph, starting at vertex start.

    Precondition:  start is a vertex;  unvisited[i] is true if vertex i has
        not yet been visited, and is false otherwise.
    Postcondition: Vector unvisited has been updated.
   -----------------------------------------------------------------------*/

}; // end of Digraph class template declaration

//--- Definition of data()
template <typename DataType>
inline DataType Digraph<DataType>::data(int k) const
{ 
  return myAdjacencyLists[k].data;
}

//--- Definition of read()
template <typename DataType>
void Digraph<DataType>::read(ifstream & inStream)
{
  Digraph<DataType>::VertexInfo vi;
  int n,           // number of vertices adjacent to some vertex
      vertex;      // the number of a vertex

  // Put a garbage 0-th value so indices start with 1, as is customary
  myAdjacencyLists.push_back(vi); 

  // Construct adjacency list representation
  for (;;)
  {
    inStream >> vi.data;
    if (inStream.eof()) break;

    inStream >> n;
    list<int> adjList;      // construct empty list
    for (int i = 1; i <= n; i++)
    {
      inStream >> vertex;
      adjList.push_back(vertex);
    }
    vi.adjacencyList = adjList;
    myAdjacencyLists.push_back(vi);
  }
}

//--- Definition of display()
template <typename DataType>
void Digraph<DataType>::display(ostream & out)
{
  out << "Adjacency-List Representation: \n";
  for (int i = 1; i < myAdjacencyLists.size(); i++)
  {
    out << i << ": " <<  myAdjacencyLists[i].data << "--";
    for (list<int>::iterator 
          it = myAdjacencyLists[i].adjacencyList.begin();
          it != myAdjacencyLists[i].adjacencyList.end(); it++)
      out << *it << "  ";
    out << endl;
  }
}
  
//-- Definitions of depthFirstSearch() and depthFirstSearchAux()
template <typename DataType>
inline void Digraph<DataType>::depthFirstSearch(int start)
{
  vector<bool> unvisited(myAdjacencyLists.size(), true);
  depthFirstSearchAux(start, unvisited);
}

template <typename DataType>
void Digraph<DataType>::depthFirstSearchAux(
                                   int start, vector<bool> & unvisited)
{
  // Add statements here to process myAdjacencyLists[start].data
  cout << myAdjacencyLists[start].data << endl;

  unvisited[start] = false;
  // Traverse its adjacency list, performing depth-first 
  // searches from each unvisited vertex in it.
  for (list<int>::iterator 
         it = myAdjacencyLists[start].adjacencyList.begin();
         it != myAdjacencyLists[start].adjacencyList.end(); it++)
    // check if current vertex has been visited
    if (unvisited[*it])
      // start DFS from new node
      depthFirstSearchAux(*it, unvisited); 
}

//--- Definition of shortestPath()
template<typename DataType>
vector<int> Digraph<DataType>::shortestPath(int start, int destination)
{
  int n = myAdjacencyLists.size(); // number of vertices (#ed from 1)
  vector<int> distLabel(n,-1),     // distance labels for vertices, all
                                   // marked as unvisited (-1)
              predLabel(n);        // predecessor labels for vertices
  // Perform breadth first search from start to find destination,
  // labeling vertices with distances from start as we go.
  distLabel[start] = 0;
  int distance = 0,                // distance from start vertex
      vertex;                      // a vertex
  queue<int> vertexQueue;          // queue of vertices
  vertexQueue.push(start);
  while (distLabel[destination] < 0 && !vertexQueue.empty())
  {
    vertex = vertexQueue.front();
    vertexQueue.pop();
    if (distLabel[vertex] > distance)
      distance++;
    for (list<int>::iterator 
         it = myAdjacencyLists[vertex].adjacencyList.begin();
         it != myAdjacencyLists[vertex].adjacencyList.end(); it++)
      if (distLabel[*it] < 0)
      {
        distLabel[*it] = distance + 1;
        predLabel[*it] = vertex;
        vertexQueue.push(*it);
      }
  }
  distance++;

  // Now reconstruct the shortest path if there is one
  vector<int> path(distance+1);
  if (distLabel[destination] < 0)
    cout << "Destination not reachable from start vertex\n";
  else
  {
    path[distance] = destination;
    for (int k = distance - 1; k >= 0; k--)
      path[k] = predLabel[path[k+1]];
  }

  return path;
}
