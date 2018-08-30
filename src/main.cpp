#include <fstream>
#include <iostream>
#include "ausmap.hpp"
#include "greedy.hpp"
#include "astar.hpp"
using namespace std;

int main(){
	Graph *g = new Graph();
	ifstream file("australia.csv");
	g->build(file);
	file.close();

	Greedy greddy(g, 5, 219); 
	cout << greddy.run() << endl;
	Astar astar(g, 5, 219);
	cout << astar.run() << endl;

	return 0;
}