class Solution {
  public:
    int zigzagSequence(vector<vector<int>> &mat)
    {
        int n = mat.size();
    
        // dp[i][j] stores the maximum zigzag sum ending at row i and column j.
        vector<vector<int>> dp(n, vector<int>(n, 0));
    
        // First row starts the sequence.
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = mat[0][j];
        }
    
        for (int i = 1; i < n; i++)
        {
            for (int currCol = 0; currCol < n; currCol++)
            {
                for (int prevCol = 0; prevCol < n; prevCol++)
                {
    
                    // Consecutive elements must come from different columns.
                    if (currCol != prevCol)
                    {
                        dp[i][currCol] = max(dp[i][currCol], dp[i - 1][prevCol] + mat[i][currCol]);
                    }
                }
            }
        }
    
        int res = 0;
    
        // The answer is the maximum value in the last row.
        for (int x : dp[n - 1])
            res = max(res, x);
    
        return res;
    }
};