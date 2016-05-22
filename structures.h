#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <vector>

struct Edge{
	Edge(int s, int d, int w){
		source = s;
		dest = d;
		weight = w;
	}

	int source, dest, weight;
};

struct Graph{
	Graph(int v, int e){
		V = v;
		E = e;
	}

	int V, E;
	std::Vector<Edge> edges();
};

struct Subset{
	Subset(int p, int r){
		parent = p;
		rank = r;
	}
	int parent, rank;
};

#endif