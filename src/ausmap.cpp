#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

#define MAXC 220

class Graph {
private:
	vector<vector<int> > adjList;
	void addNode(char* str);
	vector<pair<double, double> > coords;
	vector<string> names;
public:
	Graph();
	void build(ifstream &file);
	pair<double, double> getCoords(int ind) const;
	string getName(int ind) const;
};

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

pair<double, double> Graph::getCoords(int ind) const{
	return coords[ind];
}

string Graph::getName(int ind) const {
	return names[ind];
}

int main(){
	Graph *g = new Graph();
	ifstream file("australia.csv");
	g->build(file);
	file.close();
	cout << g->getName(19) << " ";
	cout << g->getCoords(119).first << endl;
	return 0;
}