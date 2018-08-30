#ifndef ASTAR_H
#define ASTAR_H
#include <vector>
#include "ausmap.hpp"
#include "graphsearch.hpp"

class Astar : public GraphSearch{
public:
	Astar(Graph *g, int start, int destiny) : GraphSearch(g, start, destiny) {};
	double run();
};

#endif