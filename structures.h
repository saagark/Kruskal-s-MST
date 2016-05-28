#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <vector>
#include <algorithm>
#include <iterator>

struct Edge{
	Edge(int s, int d, int w){
		source = s;
		dest = d;
		weight = w;
	}

	Edge(){
		source = 0;
		dest = 0;
		weight = 0;
	}

	int source, dest, weight;
};

struct Graph{
	Graph(int v, int e){
		V = v;
		E = e;
	}

	int getV(){
		return V;
	}

	int V, E;
	std::vector<Edge> edges;
};


#endif