#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include "ausmap.hpp"

using namespace std;

#define MAXC 220

Graph::Graph (){
	adjList.assign(MAXC, vector<int> ());
	names.assign(MAXC, "");
	coords.resize(MAXC);
}

void Graph::build(ifstream &file){
	while(file){
		char str[255];
		file.getline(str, 255);
		if(file) addNode(str);
	}
}

void Graph::addNode(char *str){
	char *pch;
	int id = atoi(strtok(str, ","));
	if(id == 0) return; // Skip first line
	string name(strtok(NULL, ","));
	// cout << id << " " << name << endl;
	double x, y;
	x = atof(strtok(NULL, ","));
	y = atof(strtok(NULL, ","));
	if(id%2 && id > 2){ // id impar e maior que dois (tipo... todos os impares que não seja 1)
		adjList[id].push_back(id-2);
		adjList[id].push_back(id+1);
	} else if((!id%2) && x > 1){ // Id par e maior que 1 (tipo... todos os pares)
		adjList[id].push_back(id+2);
		adjList[id].push_back(id-1);
	} else { // id == 1
		adjList[id].push_back(id+1);
	}
	names[id] = name;
	coords[id] = make_pair(x, y);
}

double Graph::dist(int i, int j){
	pair<double, double> c1 = getCoords(i), c2 = getCoords(j);
	return hypot(c1.first - c2.first, c1.second - c2.second);
}

pair<double, double> Graph::getCoords(int ind) const{
	return coords[ind];
}

string Graph::getName(int ind) const {
	return names[ind];
}

int Graph::size() const {return adjList.size();}

vector<int> Graph::getAdjList(int ind) const{ return adjList[ind]; }