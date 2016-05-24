#include "kruskal.h"
#include <iostream>
using namespace std;

int main(){
	int vertices, edges;

	cin >> vertices;
	cin >> edges;
	Kruskal * k = new Kruskal(vertices,edges);

	int source, dest, weight;
	for(int i = 0; i < edges; i++){
		cin >> source;
		cin >> dest;
		cin >> weight;
		Edge edgeToAdd(source, dest, weight);
		k->add(edgeToAdd);
	}


	k->KruskalsAlgorithm();
}