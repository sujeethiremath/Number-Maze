#include "Graph.h"
#include "WeightedVertex.h"
#include<vector>
#include<utility>
#include<set>
#include<queue>
#include<iostream>

//function to read input and form the horizontal and vertical edges for the given maze
void readMaze(Graph<WeightedVertex> &G)
{
		vector<vector<unsigned>> input;
		vector<unsigned> columnInput;
		unsigned rows, columns;
		cin >> rows;
		cin >> columns;

		//stores the given inputs into the two dimensional container
		for(unsigned i=0; i<rows; i++)
		{
			for(unsigned j=0; j<columns; j++)
			{
					unsigned temp;
					cin >> temp;
					columnInput.push_back(temp);
			}
			input.push_back(columnInput);
			columnInput.clear();
		}

		//creates the horizontal connnections between all the vertices of the given graph maze
		for(unsigned i=0,p=0; i<rows; i++,p++)
		{
			for(unsigned j=1; j<columns; j++)
			{
				WeightedVertex WU(p,input[i][j-1]);
				++p;
				WeightedVertex WV(p, input[i][j]);
				G.add(WU,WV);
			}
		}

		//creates the vertical connections between all the vertices of the given graph maze
		unsigned k=0;
		for(unsigned m=1; m<rows; m++)
		{
			for(unsigned n=0; n<columns; n++)
			{
				WeightedVertex WUx(k,input[m-1][n]);
				WeightedVertex WVx(k+columns,input[m][n]);
				k++;
				G.add(WUx,WVx);
			}
		}
}

//Calculates the distances to all the vertices from the given vertex in the Graph
map<WeightedVertex,int> getSSSP( Graph<WeightedVertex> G , const WeightedVertex src )
{
	const unsigned maxWeight = 999; //infinity
	typedef pair <unsigned, WeightedVertex> dWeights;
	vector<bool> visited;
	map<WeightedVertex,int> distanceretu;
	vector<int> distance;
	priority_queue<dWeights, vector<dWeights>, greater<dWeights> > Q;  //priority queue
	set<WeightedVertex> SF = G.getVertices();
	visited.resize(SF.size());
	distance.resize(SF.size());
	unsigned i=0;
	//initialization
	for(auto itc = SF.begin(); itc!=SF.end(); ++itc)
	{
		if((*itc).getVertexName()==src.getVertexName())
		{
			distance[i] = src.getVertexWeight();
			visited[i] = false;
		}
		else
		{
			distance[i] = maxWeight;
			visited[i] = false;
		}
		++i;
	}
	Q.push(make_pair(src.getVertexWeight(),src));
	while(Q.empty()==false)
	{
		WeightedVertex u = Q.top().second;//<unsigned, WeightedVertex>
		distanceretu.insert(pair<WeightedVertex,int>(u,Q.top().first));
		unsigned du = distance[u.getVertexName()]; //pair<WeightedVertex,int>
		visited[u.getVertexName()] = true; //<WeightedVertex,bool>
		Q.pop();
		vector<WeightedVertex> adjecent = G.getAdjecentVertices(u);
		for(unsigned i=0; i<adjecent.size(); i++)
		{
			unsigned it = distance[adjecent[i].getVertexName()];
			bool fitt = visited[(adjecent[i]).getVertexName()];
			if(it > du && fitt==false && it == maxWeight)
			{
				distance[adjecent[i].getVertexName()] = du + (adjecent[i]).getVertexWeight();
				Q.push(make_pair(distance[adjecent[i].getVertexName()],adjecent[i]));
			}
		}
	}
	return distanceretu;
}
