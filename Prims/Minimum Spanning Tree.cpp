#include <iostream>
// #include <vector>
// #include <queue>
// #include <utility>
// #include <set>


#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

class Graph {
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.  

    int spanningTree(int V, vector<vector<int>> adj[]) {


        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, 0});
        vector<bool> inMST(V, false);
        int sum = 0;
        set<pair<int, int>> mstEdges;
        
        while(!pq.empty()) {
            
            auto p = pq.top();
            pq.pop();
            
            int wt     = p.first;
            int node   = p.second;
            
            if(inMST[node] == true)
                continue;
            
            inMST[node] = true; //added to mst
            sum += wt;
            
         for (int i = 0; i < adj[node].size(); ++i) {
            int neighbor = adj[node][i][0];
            int neighborWeight = adj[node][i][1];

            if (!inMST[neighbor]) {
                pq.push({neighborWeight, neighbor});
            }
        }

        }

        // Print the edges of the Minimum Spanning Tree
        cout << "Minimum Spanning Tree Edges:" << endl;
        for (int i = 1; i < V; ++i) {
            int parent = i;
            int child = -1;
            for (int j = 0; j < adj[parent].size(); ++j) {
            int neighbor = adj[parent][j][0];
            if (inMST[neighbor]) {
                child = neighbor;
                break;
            }
        }
            if (child != -1) {
                mstEdges.insert({min(parent, child), max(parent, child)});
            }
        }
        for(auto &edge : mstEdges) {
            cout << edge.first << " - " << edge.second << endl;
        }
        
        return sum;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj[V];

    cout << "Enter edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // assuming an undirected graph
    }

    Graph graph;

    int sumOfWeights = graph.spanningTree(V, adj);

    cout << "Sum of weights of edges of the Minimum Spanning Tree: " << sumOfWeights << endl;

    return 0;
}




// Enter the number of vertices and edges: 5 7
// Enter edges (source, destination, weight):
// 0 1 2
// 0 2 3
// 1 2 1
// 1 3 4
// 1 4 5
// 2 3 7
// 3 4 6
// Minimum Spanning Tree Edges:
// 0 - 1
// 1 - 2
// 0 - 3
// 1 - 4
// Sum of weights of edges of the Minimum Spanning Tree: 10
