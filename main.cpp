#include "kruskal.h"
#include <iostream>
using namespace std;

int main(){
	Kruskal * k = new Kruskal(4,6);
// 	1 2 10
// 2 3 9
// 1 4 4
// 2 4 7
// 1 3 5
// 3 4 2
	Edge *a = new Edge(1,2,10);
	Edge *c = new Edge(2,3,9);
	Edge *b = new Edge(1,4,4);
	Edge *d = new Edge(2,4,7);
	Edge *e = new Edge(1,3,5);
	Edge *f = new Edge(3,4,2);

	k->add(*a);
	k->add(*b);
	k->add(*c);
	k->add(*d);
	k->add(*e);
	k->add(*f);

	k->KruskalsAlgorithm();
}