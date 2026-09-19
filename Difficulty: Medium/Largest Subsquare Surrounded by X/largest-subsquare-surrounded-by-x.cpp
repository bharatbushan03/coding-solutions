#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int largestSubsquare(vector<vector<char>> &mat) {
        int n = mat.size();
        if (n == 0) return 0;

        vector<vector<int>> hor(n, vector<int>(n, 0));
        vector<vector<int>> ver(n, vector<int>(n, 0));

        // Step 1: Precompute horizontal and vertical consecutive 'X' counts
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 'X') {
                    hor[i][j] = (j == 0) ? 1 : hor[i][j - 1] + 1;
                    ver[i][j] = (i == 0) ? 1 : ver[i - 1][j] + 1;
                }
            }
        }

        int max_side = 0;

        // Step 2: Iterate from bottom-right to find the largest valid square
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Maximum possible side length with bottom-right corner at (i, j)
                int k = min(hor[i][j], ver[i][j]);

                // Decrement k until a valid square boundary is found
                while (k > max_side) {
                    if (hor[i - k + 1][j] >= k && ver[i][j - k + 1] >= k) {
                        max_side = k;
                        break;
                    }
                    k--;
                }
            }
        }

        return max_side;
    }
};