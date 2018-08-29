#include <fstream>
#include <iostream>
#include "ausmap.hpp"
#include "greedy.hpp"
using namespace std;

int main(){
	Graph *g = new Graph();
	ifstream file("australia.csv");
	g->build(file);
	file.close();

	Greedy greddy(g, 5, 219); 
	cout << greddy.run() << endl;

	return 0;
}