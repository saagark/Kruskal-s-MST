#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "structures.h"

class Kruskal{
	public:
		Subset* subset;
		Graph* graph;

	private:

		Kruskal();
		int find(int i);
		void union(int x, int y);
		void KruskalsAlgorithm();

};

#endif