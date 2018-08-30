#ifndef GRAPHSEARCH_H
#define GRAPHSEARCH_H
#include <vector>
#include "ausmap.hpp"

class GraphSearch {
protected:
	vector<double> heuristica;
	vector<bool> visited;
	vector<double> distance;
	Graph *g;
	int start, destiny;
	void buildHeuristics();
public:
	GraphSearch(Graph *g, int start, int destiny);
	double run();
};

#endif