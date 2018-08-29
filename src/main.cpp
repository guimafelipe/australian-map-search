#include <fstream>
#include <iostream>
#include "ausmap.hpp"
using namespace std;

int main(){
	Graph *g = new Graph();
	ifstream file("australia.csv");
	g->build(file);
	file.close();
	cout << g->getName(19) << " ";
	cout << g->getCoords(119).first << endl;
	return 0;
}