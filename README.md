Consider a number maze represented as a two dimensional array of numbers consisting of only the numbers between 0 and
9. The maze can be traversed following any orthogonal direction (i.e., north, south, east and west). Considering that each
cell represents a cost, then finding the minimum cost to travel the maze from one entry point to an exit point may pose
a reasonable challenge, although there must be a graph algorithm that we can apply to solve this problem.
The task is to find the minimum cost value to go from the top–left corner to the bottom–right corner of a given number maze

              0   3   1   2   9
              7   3   4   9   9
              1   7   5   5   3
              2   3   4   2   5

of size N×M, where N denotes the number of rows and M denotes the number of columns. Additionally, 1≤N, M≤999.
Note that the solution for the given example is 24.

Input


All input comes from standard input, so using cin should be sufficient. The first number indicates the number of rows, N,
and the second number indicates the number of columns, M. The next N×M numbers (between 0 and 9) indicate the values
at each cell of the maze. Each value is separated by whitespace.


Sample Input


Here is the input corresponding to the number maze given in Figure 1:


          4     5
          0     3     1     2     9
          7     3     4     9     9          
          1     7     5     5     3
          2     3     4     2     5
          
          
And here is another simple number maze:


          3     3
          1     2     3
          4     5     6
          7     8     9
          
          
Output


The output consists of a single number: the cost of the minimum cost path from the top–left corner to the bottom–right
corner of the given maze. Altough there may be more than one path from the top–left corner to the bottom–right corner
of a maze, the minimum cost should be the same.


Sample Output

    Number Maze has 9 vertices and 24 edges:
      V={1,2,3,4,5,6,7,8,9}
      E={(1,2),(1,4),(2,1),(2,3),(2,5),(3,2),(3,6),(4,1),(4,5),(4,7),(5,2),(5,4),(5,6),(5,8),
       (6,3),(6,5),(6,9),(7,4),(7,8),(8,5),(8,7),(8,9),(9,6),(9,8)}
    Distances from 1: 1 3 6 5 8 12 12 16 21
    21


Following important functions are included in the program:

1. void readMaze( Graph<WeightedVertex> G ) – reads in the maze from standard input and uses a
Graph object to represent it. The vertices of type WeightedVertex are read first, then the vertices are connected based
on the maze configuration.

2. map<WeightedVertex,int> getSSSP( Graph<WeightedVertex> G , const WeightedVertex src ) - 
performs a modified version of Dijkstra’s SSSP algorithm so that it works on a vertex–weighted graph instead of the
standard algorithm that works for edge–weighted graphs. Note that the total weight of the path is the sum of the
weights of all the vertices along that path. The shortest distances from the indicated source to all the other vertices in
the graph are returned as a map object.

          
