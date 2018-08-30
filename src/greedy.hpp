#ifndef GREEDY_H
#define GREEDY_H
#include "ausmap.hpp"
#include "graphsearch.hpp"
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

class Greedy : public GraphSearch{
public:
	Greedy(Graph *g, int start, int destiny) : GraphSearch(g, start, destiny) {};
	double run();
};
#endif