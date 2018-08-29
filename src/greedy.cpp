#include "ausmap.hpp"
#include "greedy.hpp"
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;

// class Greedy {
// private:
// 	vector<double> heuristica;
// 	vector<bool> visited;
// 	Graph *g;
// 	double search(int curr);
// public:
// 	Greedy(Graph* g, int destiny, int start);
// 	void buildHeuristics();
// 	double run();
// }

Greedy::Greedy(Graph* g, int start, int destiny){
	this->destiny = destiny;
	this->start = start;
	this->g = g;
	buildHeuristics();
}

void Greedy::buildHeuristics(){
	int n = g->size();
	heuristica.resize(n);
	visited.assign(n, false);
	pair<double, double> dest = g->getCoords(destiny), curr;
	for(int i = 1; i < n; i++){
		curr = g->getCoords(i);
		heuristica[i] = hypot(dest.first - curr.first, dest.second - curr.second);
	}
}

double Greedy::run(){
	int curr = start;
	double ans = 0.0;
	ans = search(start);
	return ans;
}

double Greedy::search(int curr){
	visited[curr] = true;
	// cout << curr << endl;
	if(curr == destiny) return 0.0;
	vector<int> currAdj = g->getAdjList(curr);
	int adjsz = currAdj.size();
	priority_queue<pair<double, int> , vector<pair<double, int> >, greater<pair<double, int> > > pq;
	double ans = -1.0;
	for(int i = 0; i < adjsz; i++){
		int candidate = currAdj[i];
		if(!visited[candidate]){
			pq.push(make_pair(heuristica[candidate], candidate));
		}
	}
	while(!pq.empty()){
		int candidate = pq.top().second;
		double result = search(candidate);
		if(result > -0.1){
			ans = g->dist(candidate, curr) + result;
			break;
		}
	}
	return ans;
}