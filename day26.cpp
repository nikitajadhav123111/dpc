#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // because it's undirected
    }
    bool dfs(int node, int parent, vector<bool> &visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, visited))
                    return true;
            }
            // if visited and not parent → cycle
            else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }
    bool hasCycle() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, visited))
                    return true;
            }
        }
        return false;
    }
};
int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};

    Graph g(V);
    for (auto &e : edges) {
        g.addEdge(e[0], e[1]);
    }

    if (g.hasCycle())
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
