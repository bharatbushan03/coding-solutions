class Solution {
  public:
    bool isPossible(vector<int>& arr, int mid, int k) {
        int days = 1;
        int capacity = 0;
        for (int i : arr) {
            if (capacity + i <= mid) {
                capacity += i;
            }
            else {
                capacity = i;
                days++;
            }
        }
        return days <= k;
    }
    int leastWeightCapacity(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = -1;

        int st = *max_element(arr.begin(), arr.end()), end = accumulate(arr.begin(), arr.end(), 0);

        while (st <= end) {
            int mid = st + (end - st)/2;
            if (isPossible(arr, mid, k)) {
                end = mid - 1;
                ans = mid;
            }
            else st = mid + 1;
        }

        return ans;
    }
};