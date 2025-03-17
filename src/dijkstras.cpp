#include "dijkstras.h"
#include <algorithm>

struct Node {
	int vertex;
	int weight;
	bool operator>(const Node& other) const {
        return weight > other.weight;
	}
};

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
	int numVertices = G.numVertices;
	vector<int> distances(numVertices, INF);
	vector<bool> visited(numVertices, false);
	distances[source] = 0;
	previous[source] = -1;
	
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push(Node{source, 0});

	while(!pq.empty()) {
		Node current = pq.top();
		pq.pop();
		int u = current.vertex;
		if (visited[u]) continue;
		visited[u] = true;
		for (const Edge& neighbor : G[u]) {
			int v = neighbor.dst;
			int weight = neighbor.weight;

			if (!visited[v] && distances[u] + weight < distances[v]) {
				distances[v] = distances[u] + weight;
				previous[v] = u;
				pq.push(Node{v, distances[v]});
			}
		}
	}
	return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
	vector<int> path;
	for (int i = destination; i != -1; i = previous[i])
		path.push_back(i);
	reverse(path.begin(), path.end());
	return path;
}

void print_path(const vector<int>& v, int total) {
	cout << "Total cost is " << total << endl;
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
}
