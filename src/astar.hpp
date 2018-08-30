#ifndef ASTAR_H
#define ASTAR_H
#include <vector>
#include "ausmap.hpp"

class Astar {
private:
	vector<double> heuristica;
	vector<bool> visited;
	vector<double> distance;
	Graph *g;
	int start, destiny;
	void buildHeuristics();
public:
	Astar(Graph *g, int start, int destiny);
	double run();
};

#endif