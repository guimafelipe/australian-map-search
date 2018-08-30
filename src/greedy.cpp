#include "ausmap.hpp"
#include "greedy.hpp"
#include "graphsearch.hpp"
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;

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
			double dist = g->dist(u, v);
			distance[v] = distance[u] + dist;
			pq.push(make_pair(heuristica[v], v));
		}
	}
	return -1;
}