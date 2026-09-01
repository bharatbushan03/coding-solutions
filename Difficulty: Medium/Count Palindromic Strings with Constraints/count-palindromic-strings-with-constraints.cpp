class Solution {
  public:
    int palindromicStrings(int n, int k) {
        long long MOD = 1e9 + 7;
        long long totalCount = 0;

        for (int L = 1; L <= n; ++L) {
            int r = (L + 1) / 2; // ceil(L / 2)

            if (r > k) continue; // Not enough distinct letters available

            // Calculate P(k, r) = k * (k - 1) * ... * (k - r + 1) % MOD
            long long ways = 1;
            for (int i = 0; i < r; ++i) {
                ways = (ways * (k - i)) % MOD;
            }

            totalCount = (totalCount + ways) % MOD;
        }

        return totalCount;
    }
};