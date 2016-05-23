#include "kruskal.h"
#include <algorithm>
#include <iostream>

Kruskal::Kruskal(int v, int e){
	graph = new Graph(v, e);
	subset = new Subset[v];
	MST = new Edge[v-1];

	for(int i = 0; i < v; i++){
		subset[i].parent = 0;
	}
}

void Kruskal::add(Edge e){
	graph->edges.push_back(e);
}

int Kruskal::find(int i){
	if(subset[i].parent == 0)
		return i;
	else{
		subset[i].parent = find(subset[i].parent);
		return subset[i].parent;
	}
}

void Kruskal::unionByRank(int x, int y){
	int xSet = find(x);
	int ySet = find(y);

	if (subset[xSet].rank < subset[ySet].rank)
        subset[xSet].parent = ySet;
    else if (subset[xSet].rank > subset[ySet].rank)
        subset[ySet].parent = xSet;
    else
    {
        subset[ySet].parent = xSet;
        subset[xSet].rank++;
    }
}

bool Kruskal::operator()(Edge first, Edge second){
	return first.weight < second.weight;
}


void Kruskal::KruskalsAlgorithm(){
	std::sort (graph->edges.begin(), graph->edges.end(), *this);//edgeNum < graph->getV()-1
	print();
	int index = 0;
	for(int edgeNum = 0; index < graph->E; index++){
		std::cout << "index is " << index << std::endl;
		Edge next = graph->edges[index];
		int origSource = next.source;
		int origDest = next.dest;
		int source = find(next.source);
		int dest = find(next.dest);

		if(source != dest){
			MST[edgeNum] = next;
			edgeNum++;
			unionByRank(source, dest);
			std::cout << "Edge (" << origSource << ", " << origDest << ") successfully inserted" << std::endl;
		} else {
			std::cout << "Edge (" << origSource << ", " << origDest << ") creates cycle" << std::endl;
		}
	}

}



void Kruskal::print(){
	for (int i = 0; i < graph->E ; i++){
		std::cout << graph->edges[i].source << ", " << graph->edges[i].dest << std::endl;
	}
}


void Kruskal::printMST(){
	for (int i = 0; i < graph->getV()-1 ; i++){
		std::cout << MST[i].source << ", " << MST[i].dest << std::endl;
	}
}