#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        int n = mat.size();
        int m = mat[0].size();
        int len = word.length();

        vector<vector<int>> result;

        // 8 possible directions: (dr, dc)
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                // Quick check for the first character
                if (mat[r][c] != word[0]) continue;

                bool found = false;

                // Try searching in all 8 directions
                for (int dir = 0; dir < 8; ++dir) {
                    int currR = r;
                    int currC = c;
                    int k = 0;

                    while (k < len) {
                        // Check bounds
                        if (currR < 0 || currR >= n || currC < 0 || currC >= m) {
                            break;
                        }

                        // Check character match
                        if (mat[currR][currC] != word[k]) {
                            break;
                        }

                        // Move to next cell along current direction
                        currR += dr[dir];
                        currC += dc[dir];
                        k++;
                    }

                    // If full word is matched in this direction
                    if (k == len) {
                        found = true;
                        break; // No need to check other directions for this starting cell
                    }
                }

                if (found) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};