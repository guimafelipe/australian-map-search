#include <fstream>
#include <iostream>
#include "ausmap.hpp"
#include "greedy.hpp"
#include "astar.hpp"
#include <ctime>
using namespace std;

int main(){
	Graph *g = new Graph();
	ifstream file("australia.csv");
	g->build(file);
	file.close();

	Greedy greddy(g, 5, 219); 
	clock_t begin = clock();
	double ans = greddy.run(); 
	clock_t end = clock();
	cout << "Greedy answer: " << ans << ", elapsed time: " << double(end - begin)/CLOCKS_PER_SEC << endl;

	Astar astar(g, 5, 219);
	begin = clock();
	ans = astar.run();
	end = clock();
	cout << "A* answer: " << ans << ", elapsed time: " << double(end - begin)/CLOCKS_PER_SEC << endl;

	return 0;
}