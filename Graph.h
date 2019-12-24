
	#ifndef GRAPH_H_
		#define GRAPH_H_

		#include<iostream>
		#include<set>
		#include<map>
		#include<string>
		#include<iomanip>
		#include<vector>
		#include<utility>
		#include<algorithm>

		using namespace std;

		template <class T>
		class Graph
		{
			private:
			set<T> V;
			multimap<T,T> E;
			string graphName;

			public:
			Graph(string name);
			bool add(T,T);
			set<T> getVertices() const;
			vector<T> getAdjecentVertices(T);
			template<class F>
			friend ostream& operator <<(ostream &cout, const Graph<F> &G);
		};

		#include "Graph.cpp"
	#endif
