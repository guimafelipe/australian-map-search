#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include "ausmap.hpp"
#include "graphsearch.hpp"
#include "astar.hpp"
using namespace std;

void printPath(int end, vector<int> & parent){
	int curr = end;
	while(curr != -1){
		cout << curr << " ";
		curr = parent[curr];
	}
	cout << endl;
}

#define EPS 0.0001
double Astar::run(){
	vector<int> parent (g->size() +1, -1);
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
			// printPath(destiny, parent);
			return distance[u];
		}
		vector<int> &currAdj = g->getAdjList(u);
		int n = currAdj.size();
		for(int i = 0; i < n; i++){
			int v = currAdj[i];
			double dist = g->dist(u, v);
			if(distance[u] + dist < distance[v]){
				distance[v] = distance[u] + dist;
				pq.push(make_pair(distance[v] + heuristica[v], v));
				parent[v] = u;
			}
		}
	}
	return -1;
}