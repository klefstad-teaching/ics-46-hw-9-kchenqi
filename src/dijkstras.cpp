#include "dijkstras.h"

struct Node {
	int vertex;
	int weight;
}

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
	int numVertices = G.numVertices;
	vector<int> distances(numVertcies, INF);
	vector<bool> visited(numVertices, false);
	distances[source] = 0;
	previous[source] = UNDEFINED;
	
	priority_queue<pair<int, int>> pq;
	pq.push({source, 0});

	while(!pq.empty()) {
		Node current = pq.top();
		pq.pop();
		int u = current.vertex;
		if (visited.[u]) continue;
		visited[u] = true;
		for (Edge neighbor : G[u]) {
			int v = neighbor.dst;
			int weight = neighbor.weight;

			if (!visited[v] && distances[u] + weight < distances[v]) {
				distances[v] = distances[u] + weight;
				previous[v] = u'
					pq.push(Node(v, distances[v]));
			}
		}
	}
	return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
	
}

void print_path(const vector<int>& v, int total) {
	
}
