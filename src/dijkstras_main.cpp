#include "dijkstra.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	Graph G;
	string file_name = "large.txt";
	file_to_graph(file_name, G);
}