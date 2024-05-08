#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void dfs(int src, unordered_map<int, vector<int>>& adj, vector<bool>& vis, vector<int>& result) {
    vis[src] = true;
    result.push_back(src);

    for (int i = 0; i < adj[src].size(); i++) {
        int nbr = adj[src][i];

        if (!vis[nbr]) {
            dfs(nbr, adj, vis, result);
        }
    }
}

vector<int> dfsGraph(int V, vector<int> adj[]) {
    unordered_map<int, vector<int>> ad;
    vector<bool> vis(V, false);
    vector<int> result;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) { // Corrected the loop variable
            ad[i].push_back(adj[i][j]);
        }
    }

    // Perform dfs
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, ad, vis, result);
        }
    }

    return result;
}

int main() {
    int V, E;

    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        cout << "Enter the edge pairs: ";
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ansgraph = dfsGraph(V, adj);

    cout << "DFS traversal: ";
    for (int i = 0; i < ansgraph.size(); i++) {
        cout << ansgraph[i] << " ";
    }

    return 0;
}


// Enter the number of vertices: 5
// Enter the number of edges: 4
// Enter the edge pairs: 0 1
// Enter the edge pairs: 0 2
// Enter the edge pairs: 1 3
// Enter the edge pairs: 3 4
// DFS traversal: 0 1 3 4 2 
