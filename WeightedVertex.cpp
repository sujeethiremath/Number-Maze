#include "WeightedVertex.h"

WeightedVertex :: WeightedVertex(unsigned name, unsigned value)
{
  vertexName = name;
  vertexWeight = value;
}

unsigned WeightedVertex :: getVertexName() const
{
  return vertexName;
}

unsigned WeightedVertex :: getVertexWeight() const
{
  return vertexWeight;
}

void WeightedVertex :: setVertexWeight(unsigned value)
{
  vertexWeight = value;
}

bool WeightedVertex :: operator<(const WeightedVertex& WV) const
{
  return vertexName < WV.vertexName;
}
