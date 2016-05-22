#include "kruskal.h"

Kruskal(int v, int e){
	graph = new Graph(v, e);
	subset = new Subset[v];
}

