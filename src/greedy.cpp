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
	distance.resize(n);
	for(int i = 1; i < n; i++){
		heuristica[i] = g->dist(destiny, i); 
	}
}

double Greedy::run(){
	distance[start] = 0.0;
	priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
	pq.push(make_pair(heuristica[start], start));
	while(!pq.empty()){
		pair<double, int> front = pq.top();
		pq.pop();
		double cost = front.first;
		int u = front.second;
		if(visited[u]) continue;
		visited[u] = true;
		if(u == destiny){
			return distance[u];
		}
		vector<int> &currAdj = g->getAdjList(u);
		int n = currAdj.size();
		for(int i = 0; i < n; i++){
			int v = currAdj[i];
			if(visited[v]) continue;
			int dist = g->dist(u, v);
			distance[v] = distance[u] + dist;
			pq.push(make_pair(heuristica[v], v));
		}
	}
}

// double Greedy::search(int curr){
// 	// cout << curr << endl;
// 	if(curr == destiny) return 0.0;
// 	vector<int> currAdj = g->getAdjList(curr);
// 	int adjsz = currAdj.size();
// 	double ans = -1.0;
// 	for(int i = 0; i < adjsz; i++){
// 		int candidate = currAdj[i];
// 		if(!visited[candidate]){
// 			pq.push(make_pair(heuristica[candidate], candidate));
// 		}
// 	}
// 	while(!pq.empty()){
// 		int candidate = pq.top().second;
// 		double result = search(candidate);
// 		if(result > -0.1){
// 			ans = g->dist(candidate, curr) + result;
// 			break;
// 		}
// 	}
// 	return ans;
// }