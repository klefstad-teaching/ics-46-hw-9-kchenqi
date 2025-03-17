#include "dijkstras.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	Graph G;
	string file_name = "src/large.txt";
	file_to_graph(file_name, G);
	int source = 7;
	int destination = 15;
	vector<int> previous(G.numVertices, -1);
    vector<int> distances = dijkstra_shortest_path(G, source, previous);
	vector<int> path = extract_shortest_path(distances, previous, destination);
	print_path(path, distances[destination]);
}