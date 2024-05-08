#include <iostream>
// #include <vector>
// #include <queue>
// #include <utility>
// #include <climits>
// #include <stack>
#include <bits/stdc++.h>
using namespace std;

class ShortestPath {
public:
    // Function to find the shortest distance of all the vertices from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S, int dest, vector<int>& pred) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // min heap

        vector<int> result(V , INT_MAX);
        result[S] = 0;
        
        // weight , Node
        pq.push({0 , S});
        pred.assign(V, -1); // Initialize predecessor array
        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto nbr : adj[node]) {
                // node , weight(distance)
                int adjNode = nbr[0];
                int wt = nbr[1];
                if(d + wt < result[adjNode]) {
                    result[adjNode] = d + wt;
                    pred[adjNode] = node; // Update predecessor
                    pq.push({d + wt , adjNode});
                }
            }
        }
        return result;
    }

    // Function to get the shortest path from source to destination
    vector<int> getShortestPath(int dest, const vector<int>& pred) {
        vector<int> path;
        for (int v = dest; v != -1; v = pred[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    int V, E, S, dest;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj[V];

    cout << "Enter edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        // Assuming an undirected graph, so we add both directions.
        adj[v].push_back({u, weight});
    }

    cout << "Enter the source vertex: ";
    cin >> S;

    cout << "Enter the destination vertex: ";
    cin >> dest;

    ShortestPath sp;
    vector<int> pred;
    vector<int> shortestDistances = sp.dijkstra(V, adj, S, dest, pred);

    cout << "Shortest distance from source vertex " << S << " to destination vertex " << dest << ": " << shortestDistances[dest] << endl;

    // Get shortest path
    vector<int> shortestPath = sp.getShortestPath(dest, pred);

    cout << "Shortest path from source vertex " << S << " to destination vertex " << dest << ": ";
    for (size_t i = 0; i < shortestPath.size(); ++i) {
        cout << shortestPath[i];
        if (i != shortestPath.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;

    return 0;
}


// Enter the number of vertices and edges: 4 5
// Enter edges (source, destination, weight):
// 0 1 2
// 0 2 3
// 1 2 1
// 1 3 1
// 2 3 2
// Enter the source vertex: 0
// Enter the destination vertex: 3
// Shortest distance from source vertex 0 to destination vertex 3: 3
// Shortest path from source vertex 0 to destination vertex 3: 0 -> 1 -> 3
