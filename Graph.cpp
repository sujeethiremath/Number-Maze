
	#include "Graph.h"

	//constructor to initialize graph object
	template<class T>
	Graph<T> :: Graph(string name)
	{
		graphName = name;
	}

	//returns vertices
	template<class T>
	set<T> Graph<T> :: getVertices() const
	{
		return V;
	}

	//adds the edges according to the type of graph
	template <class T>
	bool Graph<T> :: add(T u,T v)
	{
			V.insert(u);
			V.insert(v);
			E.insert(pair<T,T>(u,v));
			E.insert(pair<T,T>(v,u));

		return true;
	}

//returns all the adjecent vertices stored in vector for the given vertex
	template <class T>
	vector<T> Graph<T> :: getAdjecentVertices(T u)
	{
		vector<T> adjecent;
		auto ret = E.equal_range(u);
		for(auto it=ret.first; it!=ret.second; ++it)
		{
				adjecent.push_back(it->second);
		}
		return adjecent;
	}

	//overloaded operator to print the graph
	template <class F>
	ostream& operator <<(ostream &cout,const Graph<F> &G)
	{

		cout<<G.graphName;

		set<pair<F,F>> printVect;
		for(auto itr = G.E.begin(); itr!=G.E.end();++itr)
		{
			printVect.insert(make_pair(itr->first,itr->second));
		}

		//sort(printVect.begin(),printVect.end(),compareObjects);
		cout<<" has "<<G.V.size()<<" vertices and "<<G.E.size()<<" edges:"<<endl;
		cout<<setw(5)<<"V={";
		for(auto it=G.V.begin();it!=G.V.end();++it)
		{
	        cout<<(*it).getVertexWeight();
	        auto j = it;
	        ++j;
	        cout<<(j == G.V.end()?"":",");
		}
		cout<<"}"<<endl;

		cout<<setw(5)<<"E={";

		for(auto itr = printVect.begin(); itr!=printVect.end();++itr)
		{
	        cout<<"(";
					cout<<(itr->first).getVertexName()<<" ";
	        cout<<(itr->first).getVertexWeight()<<",";
					cout<<(itr->second).getVertexName()<<" ";
	        cout<<(itr->second).getVertexWeight()<<")";
	        auto k = itr;
	        ++k;
	        cout<<(k==printVect.end()?"":",");
		}

		cout<<"}";

		return cout;
	}
