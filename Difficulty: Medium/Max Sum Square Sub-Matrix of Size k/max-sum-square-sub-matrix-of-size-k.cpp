class Solution {
public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        
        // Step 1: Create a 2D prefix sum array with dimensions (n + 1) x (n + 1)
        vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pre[i + 1][j + 1] = mat[i][j] + pre[i][j + 1] + pre[i + 1][j] - pre[i][j];
            }
        }
        
        int maxSum = INT_MIN;
        
        // Step 2: Find the maximum sum of all k x k sub-grids using the prefix sum matrix
        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                int r2 = i + k;
                int c2 = j + k;
                
                int currentSum = pre[r2][c2] - pre[i][c2] - pre[r2][j] + pre[i][j];
                maxSum = max(maxSum, currentSum);
            }
        }
        
        return maxSum;
    }
};