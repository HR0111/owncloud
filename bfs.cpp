#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void bfs(int src, unordered_map<int,vector<int>>& adj, vector<bool>& vis, vector<int>& result) {
    queue<int> q;
    q.push(src);
    vis[src] = true;
    result.push_back(src);

    while (!q.empty()) {
        int fNode = q.front();
        q.pop();
        for (int i = 0; i < adj[fNode].size(); i++) {
            int nbr = adj[fNode][i];
            if (!vis[nbr]) {
                q.push(nbr);
                vis[nbr] = true;
                result.push_back(nbr);
            }
        }
    }
}

// Function to return Breadth First Traversal of given graph.
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    unordered_map<int,vector<int>> adjMap;
    vector<bool> vis(V, false);
    vector<int> result;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            adjMap[i].push_back(adj[i][j]);
        }
    }

    // Assuming the source vertex is 0, you can change it as per requirement
    bfs(0, adjMap, vis, result);

    return result;
}

int main() {
    int E;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<int> adj[E];
    cout << "Enter the edges (vertex pairs, 0-indexed):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    int V = E; // Assuming vertices are numbered from 0 to E-1
    vector<int> bfsTraversal = bfsOfGraph(V, adj);

    cout << "Breadth First Search (BFS) Traversal: ";
    for (int i = 0; i < bfsTraversal.size(); i++) {
        cout << bfsTraversal[i] << " ";
    }
    cout << endl;

    return 0;
}
