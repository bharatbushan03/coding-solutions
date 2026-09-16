class Solution {
public:
    int dominantPairs(vector<int> &arr) {
        int n = arr.size();
        int half = n / 2;

        // Sort both halves independently
        sort(arr.begin(), arr.begin() + half);
        sort(arr.begin() + half, arr.end());

        int count = 0;
        int j = half;

        // Two-pointer approach
        for (int i = 0; i < half; i++) {
            while (j < n && arr[i] >= 5 * arr[j]) {
                j++;
            }
            count += (j - half);
        }

        return count;
    }
};