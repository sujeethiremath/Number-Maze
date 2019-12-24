#ifndef WEIGHTEDVERTEX_H_
#define WEIGHTEDVERTEX_H_

using namespace std;

class WeightedVertex
{
private:
	unsigned vertexName; //stores the name of the vertex
	unsigned vertexWeight; //stores the weight of the vertex

public:
	//constructor to initialize object with given name and value of vertex
	WeightedVertex(unsigned name, unsigned value);

	//returns vertex name
	unsigned getVertexName() const;

	//returns vertex weight
	unsigned getVertexWeight() const;

	//bool operator to sort the set according to the name of the vertices
	bool operator<(const WeightedVertex& WV) const;

	//function to change the weight of the vertex
	void setVertexWeight(unsigned value);
};
#endif
