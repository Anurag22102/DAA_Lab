#include <iostream>
using namespace std;

// Dijkstra's algorithm for dense graphs
vector<int> dijkstra(int n,
					vector<vector<pair<int, int> > >& adj,
					int src)
{
	// Array to store minimum distances
	vector<int> dis(n + 1, INT_MAX);

	// Array to mark visited vertices
	vector<bool> vis(n + 1, false);

	// Set the distance to the source as 0
	dis[src] = 0;

	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (v == -1 || dis[j] < dis[v]))
				v = j;
		}

		if (dis[v] == INT_MAX)
			break;
		// Mark vertex v as visited
		vis[v] = true;

		for (auto edge : adj[v]) {
			// Neighbor vertex
			int x = edge.first;
			// Edge weight
			int wt = edge.second;

			// Update the distance if a shorter path is
			// found
			if (dis[v] + wt < dis[x]) {
				dis[x] = dis[v] + wt;
			}
		}
	}
	// Return the array of minimum distances
	return dis;
}

int main()
{
	// Number of vertices
	int n = 7;
	// Adjacency list
	vector<vector<pair<int, int> > > adj(n + 1);

	// Example: adding edges to the adjacency list

	// Edge from vertex 1 to 2 with weight 3
	adj[1].push_back({ 2, 2 });
	// Edge from vertex 1 to 3 with weight 5
	adj[1].push_back({ 4, 1 });
	// Edge from vertex 2 to 3 with weight 1
	adj[2].push_back({ 4, 3 });
	// Edge from vertex 3 to 4 with weight 2
	adj[2].push_back({ 5, 10 });
	// Edge from vertex 2 to 4 with weight 7
	adj[3].push_back({ 1, 4 });
    adj[3].push_back({ 6, 5 });
    adj[4].push_back({ 3, 2 });
    adj[4].push_back({ 5, 2 });
    adj[4].push_back({ 7, 4 });
    adj[5].push_back({ 7, 6 });
    adj[7].push_back({ 6, 1 });
  



	int src = 1; // Source vertex

	vector<int> distances = dijkstra(n, adj, src);

	// Print the minimum distances from the source to all
	// other vertices
	for (int i = 1; i <= n; i++) {
		cout << "Minimum distance from vertex " << src
			<< " to " << i << " is " << distances[i]
			<< "\n";
	}

	return 0;
}