#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include "ausmap.hpp"
#include "astar.hpp"
using namespace std;


Astar::Astar(Graph *g, int start, int destiny){ 
	this->g = g;
	this->start = start;
	this->destiny = destiny;
	buildHeuristics();
}

#define INF 1e9
void Astar::buildHeuristics(){
	int n = g->size();
	heuristica.resize(n);
	distance.assign(n, INF);
	visited.assign(n, false);
	for(int i = 1; i < n; i++){
		heuristica[i] = g->dist(destiny, i); 
	}
}

#define EPS 0.0001
double Astar::run(){
	distance[start] = 0.0;
	priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
	pq.push(make_pair(0.0 ,start));
	while(!pq.empty()){
		pair<double, int> front = pq.top();
		pq.pop();
		double cost = front.first;
		int u = front.second;
		if(cost > distance[u] + heuristica[u]) continue;
		if(visited[u]) continue;
		visited[u] = true;
		if(u == destiny){
			return distance[u];
		}
		vector<int> &currAdj = g->getAdjList(u);
		int n = currAdj.size();
		for(int i = 0; i < n; i++){
			int v = currAdj[i];
			int dist = g->dist(u, v);
			if(distance[u] + dist < distance[v] + EPS){
				distance[v] = distance[u] + dist;
				pq.push(make_pair(distance[v] + heuristica[v], v));
			}
		}
	}
	return -1;
}