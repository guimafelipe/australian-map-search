#ifndef AUSMAP_HPP
#define AUSMAP_HPP

#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

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

#endif