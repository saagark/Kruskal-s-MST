#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "structures.h"

class Kruskal{

	public:

		Kruskal(int v, int e);
		void add(Edge e);
		int find(int i);
		void unionByRank(int x, int y);
		void KruskalsAlgorithm();
		bool operator()(Edge first, Edge second);
		void print();
		void printMST();
		void printSet();

	private:
		int* subset;
		Graph* graph;
		Edge* MST;
};

#endif