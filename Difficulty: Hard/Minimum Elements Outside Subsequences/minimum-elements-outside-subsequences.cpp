class Solution {
public:
    int minCount(vector<int>& arr) {
        int n = arr.size();

        // dp[inc_last][dec_last] stores max elements included
        // inc_last ranges from 0 to 100
        // dec_last ranges from 1 to 101 (101 represents empty/infinity)
        int dp[102][102];
        memset(dp, -1, sizeof(dp));

        // Base case: 0 elements processed, 0 included
        // inc_last = 0 (representing -infinity)
        // dec_last = 101 (representing +infinity)
        dp[0][101] = 0;

        for (int x : arr) {
            int next_dp[102][102];
            memset(next_dp, -1, sizeof(next_dp));

            for (int inc = 0; inc <= 100; inc++) {
                for (int dec = 1; dec <= 101; dec++) {
                    if (dp[inc][dec] == -1) continue;

                    int current_used = dp[inc][dec];

                    // Choice 1: Do not include x in either subsequence
                    next_dp[inc][dec] = max(next_dp[inc][dec], current_used);

                    // Choice 2: Add x to the increasing subsequence (must be > inc)
                    if (x > inc) {
                        next_dp[x][dec] = max(next_dp[x][dec], current_used + 1);
                    }

                    // Choice 3: Add x to the decreasing subsequence (must be < dec)
                    if (x < dec) {
                        next_dp[inc][x] = max(next_dp[inc][x], current_used + 1);
                    }
                }
            }

            // Move next_dp to dp for the next iteration
            memcpy(dp, next_dp, sizeof(dp));
        }

        // Find maximum elements that can be included
        int max_included = 0;
        for (int inc = 0; inc <= 100; inc++) {
            for (int dec = 1; dec <= 101; dec++) {
                max_included = max(max_included, dp[inc][dec]);
            }
        }

        // Minimum elements left outside = Total elements - Max elements included
        return n - max_included;
    }
};