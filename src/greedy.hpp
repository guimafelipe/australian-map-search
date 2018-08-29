#include "ausmap.hpp"
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

class Greedy {
private:
	vector<double> heuristica;
	vector<bool> visited;
	Graph *g;
    int start, destiny;
	double search(int curr);
public:
	Greedy(Graph* g, int destiny, int start);
	void buildHeuristics();
	double run();
};
