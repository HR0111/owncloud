#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool checkDFS(vector<vector<int>>& adj, int curr, vector<int>& color, int currColor) {
    color[curr] = currColor;

   for (int i = 0; i < adj[curr].size(); ++i) {
    int v = adj[curr][i];
    if (color[v] == color[curr]) {
        return false;
    } else if (color[v] == -1) {
        if (!checkDFS(adj, v, color, 1 - currColor)) {
            return false;
        }
    }
}
    return true;
}

int findMinColors(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!checkDFS(graph, i, color, 1)) {
                return -1; // Graph is not bipartite
            }
        }
    }

    // Count the number of colors used
    unordered_set<int> colorsUsed;
    for (int c : color) {
        colorsUsed.insert(c);
    }

    return colorsUsed.size();
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n);
    cout << "Enter the adjacency list for each vertex:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": "; 
        int numNeighbors;
        cin >> numNeighbors;
        for (int j = 0; j < numNeighbors; j++) {
            int neighbor;
            cin >> neighbor;
            graph[i].push_back(neighbor);
        }
    }

    int minColors = findMinColors(graph);

    if (minColors == -1) {
        cout << "The graph is not bipartite, so no coloring is possible." << endl;
    } else {
        cout << "The minimum number of colors required to color the graph is: " << minColors << endl;
    }

    return 0;
}


// Enter number of vertices: 4
// Enter number of neighbors for vertex 0: 2
// Enter neighbors for vertex 0: 1 2
// Enter number of neighbors for vertex 1: 2
// Enter neighbors for vertex 1: 0 3
// Enter number of neighbors for vertex 2: 2
// Enter neighbors for vertex 2: 0 3
// Enter number of neighbors for vertex 3: 2
// Enter neighbors for vertex 3: 1 2
// The minimum number of colors required to color the graph is: 2
// 
