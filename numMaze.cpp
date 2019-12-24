
// Main idea: Design, implement and use a variant of
// Dijkstra's single-source shortest-path (SSSP) algorithm
// originally designed for edge-weighted graphs so that it
// works for vertex-weighted graphs.

// Requirements:
//   1. Design, implementation, and use of a template Graph
//      class that allows for different vertex types.
//   2. Design, implementation, and use of a WeightedVertex
//      class to facilitate use of vertex-weighted graphs.

#include <iostream>

using namespace std;

#include "WeightedVertex.h"  // Your weighted vertex class
#include "Graph.h"           // Your graph class
#include "numMaze.h"         // For readMaze() and getSSSP()

int main()
{
    Graph< WeightedVertex > G("Number Maze");
    readMaze(G);

    cout << G << endl; // For debugging only

    set<WeightedVertex> V=G.getVertices();
    map<WeightedVertex,int> distance=getSSSP( G , *(V.begin()) );

    for( auto v : V )  // For debugging only
     {
       cout << distance[v] << " ";
       cout << endl;
     }


//    cout << distance[*(V.rbegin())] << endl;

    return 0;
}
