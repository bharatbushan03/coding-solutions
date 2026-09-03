class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // dp[0]: max sum ending at previous index if NOT replaced
        // dp[1]: max sum ending at previous index if REPLACED with 1
        long long prev_not_replaced = 0;
        long long prev_replaced = 0;

        for (int i = 1; i < n; ++i) {
            long long curr_not_replaced = std::max(
                prev_not_replaced + std::abs(arr[i] - arr[i - 1]),
                prev_replaced + std::abs(arr[i] - 1)
            );

            long long curr_replaced = std::max(
                prev_not_replaced + std::abs(1 - arr[i - 1]),
                prev_replaced // |1 - 1| = 0
            );

            prev_not_replaced = curr_not_replaced;
            prev_replaced = curr_replaced;
        }

        return std::max(prev_not_replaced, prev_replaced);
    }
};