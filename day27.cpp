#include <bits/stdc++.h>
using namespace std;
int shortestPath(int V, vector<vector<int>>& edges, int start, int end) {
    // Build adjacency list
    vector<vector<int>> adj(V);
    for (auto& e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }
    // Distance array initialized with -1
    vector<int> dist(V, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        // If we reached destination, return distance
        if (node == end) return dist[node];
        for (int nei : adj[node]) {
            if (dist[nei] == -1) { // not visited
                dist[nei] = dist[node] + 1;
                q.push(nei);
            }
        }
    }
    return -1; // no path found
}
int main() {
    int V = 5;
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{2,3},{3,4}};
    int start = 0, end = 4;
    cout << shortestPath(V, edges, start, end) << endl;
    return 0;
}
