#ifndef GREEDY_H
#define GREEDY_H
#include "ausmap.hpp"
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

class Greedy {
private:
	vector<double> heuristica;
	vector<bool> visited;
	vector<double> distance;
	// vector<vector<int> > adjList;
	Graph *g;
    int start, destiny;
	double search(int curr);
public:
	Greedy(Graph* g, int destiny, int start);
	void buildHeuristics();
	double run();
};
#endif