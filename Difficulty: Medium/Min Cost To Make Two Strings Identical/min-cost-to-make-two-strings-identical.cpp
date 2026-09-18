class Solution {
  public:
    int findMinCost(std::string &s1, std::string &s2, int costS1, int costS2) {
        int n = s1.length();
        int m = s2.length();

        // DP table to store LCS lengths
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcsLength = dp[n][m];

        // Calculate total deletion cost
        int deletionsS1 = n - lcsLength;
        int deletionsS2 = m - lcsLength;

        return (deletionsS1 * costS1) + (deletionsS2 * costS2);
    }
};