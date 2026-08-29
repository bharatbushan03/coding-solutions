#include <string>
#include <vector>

class Solution {
public:
    int countSubsequences(std::string& s, int n) {
        const int MOD = 1e9 + 7; // Standard modulo used in subsequence counting problems
        std::vector<int> dp(n, 0);

        for (char ch : s) {
            int digit = ch - '0';
            std::vector<int> next_dp = dp;

            // Option 1: Start a new single-digit subsequence with this digit
            next_dp[digit % n] = (next_dp[digit % n] + 1) % MOD;

            // Option 2: Append this digit to all previously formed subsequences
            for (int r = 0; r < n; ++r) {
                if (dp[r] > 0) {
                    int new_r = (r * 10 + digit) % n;
                    next_dp[new_r] = (next_dp[new_r] + dp[r]) % MOD;
                }
            }

            dp = std::move(next_dp);
        }

        // Return the count of subsequences with remainder 0
        return dp[0];
    }
};