#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Cell {
    int row, col, f, g, h;
    Cell(int r, int c) : row(r), col(c), f(0), g(0), h(0) {}
};

struct Compare {
    bool operator()(const Cell& a, const Cell& b) const {
        return a.f > b.f;
    }
};

bool isValid(int row, int col, int rows, int cols, vector<vector<int>>& grid) {
    return (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] != 1);
}

int heuristic(int row, int col, int destRow, int destCol) {
    return abs(destRow - row) + abs(destCol - col);
}

vector<pair<int, int>> AStar(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> dest) { 
    int rows = grid.size(), cols = grid[0].size();
    priority_queue<Cell, vector<Cell>, Compare> pq;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));


    pq.push(Cell(start.first, start.second));
    visited[start.first][start.second] = true;

    while (!pq.empty()) {
        Cell curr = pq.top();
        pq.pop();
        int row = curr.row, col = curr.col;

        if (row == dest.first && col == dest.second) {
            vector<pair<int, int>> path;
            while (parent[row][col] != make_pair(-1, -1)) {
                path.push_back({row, col});
                int temp_row = row;
            row = parent[row][col].first;
            col = parent[temp_row][col].second;

            }
            path.push_back({row, col});
            return path;
        }   

        int dRow[] = {-1, 0, 1, 0}, dCol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newRow = row + dRow[i], newCol = col + dCol[i];
            if (isValid(newRow, newCol, rows, cols, grid) && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true; 
               parent[newRow][newCol] = make_pair(row, col);
                Cell next(newRow, newCol);
                next.g = curr.g + 1;
                next.h = heuristic(newRow, newCol, dest.first, dest.second);
                next.f = next.g + next.h;
                pq.push(next);
            }
        }
    }
    return {};
}

int main() {
    vector<vector<int>> grid = {
            {0, 0, 0, 1, 0},
            {0, 1, 0, 1, 0},
            {0, 1, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 0, 1, 0}
    };
    pair<int, int> start = {0, 0};
    pair<int, int> dest = {4, 1};

    vector<pair<int, int>> path = AStar(grid, start, dest);
    if (path.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Path found: ";
        for (auto p : path) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
