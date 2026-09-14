#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Direction vectors for moving up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // 1. Mark all landmines and adjacent cells as unsafe (-1)
        vector<vector<int>> grid = mat;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    grid[i][j] = -1; // Mine cell
                    for (int d = 0; d < 4; ++d) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            grid[ni][nj] = -1; // Adjacent to mine
                        }
                    }
                }
            }
        }

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        // 2. Enqueue all safe starting points from the first column
        for (int i = 0; i < n; ++i) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                dist[i][0] = 1; // Path length counted in terms of cells visited
            }
        }

        // 3. Perform BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // If we reached any cell in the last column, return the distance
            if (c == m - 1) {
                return dist[r][c];
            }

            for (int d = 0; d < 4; ++d) {
                int nr = r + dx[d];
                int nc = c + dy[d];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return -1; // Path not reachable
    }
};