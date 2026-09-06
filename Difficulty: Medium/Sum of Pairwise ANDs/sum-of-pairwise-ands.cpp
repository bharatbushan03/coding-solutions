class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        long long total_sum = 0;
        int n = arr.size();

        // Iterate over all possible bit positions (up to 31 for values <= 10^8)
        for (int k = 0; k < 32; ++k) {
            long long count = 0;

            // Count how many numbers have the k-th bit set
            for (int i = 0; i < n; ++i) {
                if ((arr[i] >> k) & 1) {
                    count++;
                }
            }

            // Number of pairs where both numbers have the k-th bit set
            long long pairs = (count * (count - 1)) / 2;

            // Add the contribution of the k-th bit to the total sum
            total_sum += pairs * (1LL << k);
        }

        return total_sum;
    }
};