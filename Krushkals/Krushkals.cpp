#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class MST {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int kruskal(vector<vector<int>>& vec, set<pair<int, int>>& mstEdges) {
        int sum = 0;
        for(auto temp : vec) {
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if(parent_u != parent_v) {
                Union(u , v);
                sum += wt;
                mstEdges.insert({min(u, v), max(u, v)});
            }
        }

        return sum;
    }

    int spanningTree(int V, vector<vector<int>> adj[]) {
        parent.resize(V);
        rank.resize(V,0);

        for(int i = 0 ; i < V; i++) {
            parent[i] = i;
        }

        vector<vector<int>> vec;

        for(int u = 0 ; u < V ; u++) {
            for(auto temp : adj[u]) {
                int v = temp[0];
                int wt = temp[1];

                vec.push_back({u,v,wt});
            }
        }

        auto wtComparator = [&](auto &v1, auto &v2) {
            return v1[2] < v2[2];
        };

        sort(begin(vec),end(vec) , wtComparator);

        set<pair<int, int>> mstEdges;
        int sumOfWeights = kruskal(vec, mstEdges);

        // Print the edges of the Minimum Spanning Tree
        cout << "Minimum Spanning Tree Edges:" << endl;
        for(auto &edge : mstEdges) {
            cout << edge.first << " - " << edge.second << endl;
        }

        return sumOfWeights;
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

    MST mst;

    int sumOfWeights = mst.spanningTree(V, adj);

    cout << "Sum of weights of edges of the Minimum Spanning Tree: " << sumOfWeights << endl;

    return 0;
}
