class Solution {
  public:
    int mod = 1e9 + 7;

// Recursive function with Memoization
int solve(int val, int cnt, int n, int m, vector<vector<int>> &dp)
{
    // Base Case:
    // If array of size n is formed
    if (cnt == n)
    {
        return 1;
    }

    // If state already computed
    if (dp[val][cnt] != -1)
    {
        return dp[val][cnt];
    }

    int res = 0;

    // Try every value from 1 to m
    for (int i = 1; i <= m; i++)
    {
        // Valid transition:
        // Either i is a multiple of val
        // OR i is a factor of val
        if ((i % val == 0) || (val % i == 0))
        {
            res = (res + solve(i, cnt + 1, n, m, dp)) % mod;
        }
    }

    // Store and return answer
    return dp[val][cnt] = res % mod;
}

// Function to count valid arrays
int count(int n, int m)
{
    // DP[val][cnt]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    return solve(1, 0, n, m, dp);
}
};