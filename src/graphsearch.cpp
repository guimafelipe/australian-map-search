#include "graphsearch.hpp"
#include "ausmap.hpp"
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;

GraphSearch::GraphSearch(Graph *g, int start, int destiny){ 
	this->g = g;
	this->start = start;
	this->destiny = destiny;
	buildHeuristics();
}

#define INF 1e9
void GraphSearch::buildHeuristics(){
	int n = g->size();
	heuristica.resize(n);
	distance.assign(n, INF);
	visited.assign(n, false);
	for(int i = 1; i < n; i++){
		heuristica[i] = g->dist(destiny, i); 
	}
}
