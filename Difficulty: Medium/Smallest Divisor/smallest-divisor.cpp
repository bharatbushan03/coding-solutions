class Solution {
  private:
    bool isPossible(vector<int>& arr, int mid, int k) {
        int ans = 0;
        for (int val : arr) {
            if (val % mid == 0) ans += val/mid;
            else ans += (val + mid)/mid;
        }
        return ans <= k;
    }
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        int st = 1, end = *max_element(arr.begin(), arr.end());
        int ans = -1;
        
        while (st <= end) {
            int mid = st + (end - st)/2;
            if (isPossible(arr, mid, k)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }
        
        return ans;
    }
};
