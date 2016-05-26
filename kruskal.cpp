#include "kruskal.h"
#include <algorithm>
#include <iostream>

//initialize graph, disjoint set, MST
//set contents of disjoint set all to -1
Kruskal::Kruskal(int v, int e){
	graph = new Graph(v, e);
	subset = new int[v+1];
	MST = new Edge[v-1];

	for(int i = 1; i <= v; i++){
		subset[i] = -1;
	}
}

//add edge to vector
void Kruskal::add(Edge e){
	graph->edges.push_back(e);
}

//find using path compression
int Kruskal::find(int i){
	if(subset[i] < 0)
		return i;
	else{
		subset[i] = find(subset[i]);
		return subset[i];
	}
}


void Kruskal::unionByRank(int x, int y){
	int xSet = find(x);
	int ySet = find(y);

	if (subset[ySet] < subset[xSet])
        subset[xSet] = ySet;
    else if (subset[ySet] > subset[xSet])
        subset[ySet] = xSet;
    else
    {
        subset[ySet] = xSet;
        subset[xSet]--;
    }
}


//compare function for vector sort
bool Kruskal::operator()(Edge first, Edge second){
	return first.weight < second.weight;
}


void Kruskal::KruskalsAlgorithm(){
	std::sort (graph->edges.begin(), graph->edges.end(), *this);

	int weight = 0;
	int edgeNum = 0;
	for(int index = 0; index < graph->E; index++){
		Edge next = graph->edges[index];
		int origSource = next.source;
		int origDest = next.dest;
		int source = find(next.source);
		int dest = find(next.dest);
		if(source != dest){
			weight += next.weight;
			MST[edgeNum] = next;
			edgeNum++;
			unionByRank(source, dest);
			std::cout << "Edge (" << origSource << ", " << origDest << ") successfully inserted" << std::endl;
		} else {
			std::cout << "Edge (" << origSource << ", " << origDest << ") creates cycle" << std::endl;
		}

		if(edgeNum == (graph->V -1)){
			printMST();
			std::cout << weight << std::endl;
			return;
		}
		//printSet();
	}
	//if it gets to here, no MST made
	//check for corner case
	if(graph->V == 1){
		std::cout << weight << std::endl;
		return;
	}
	std::cout << "MST not found" << std::endl;

}

//prints all edges in the MST
void Kruskal::printMST(){
	for (int i = 0; i < graph->getV()-1 ; i++){
		std::cout << MST[i].source << " " << MST[i].dest << std::endl;
	}
}

// //prints out disjoint set (used for testing only)
// void Kruskal::printSet(){
// 	for (int i = 1; i <= graph->getV(); i++){
// 		std::cout << subset[i].parent << "," << subset[i].rank << " " << std::endl;
// 	}
// }
