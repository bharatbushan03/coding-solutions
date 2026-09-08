class Solution {
  private:
    bool isPossible(vector<int>& arr, int n, int mid, int k) {
        int h = 0;
        for (int val : arr) {
            h += (val + mid - 1)/mid;
        }
        
        return h <= k;
    }
  public:
    int kokoEat(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = -1;
        
        int st=1, end = *max_element(arr.begin(), arr.end());
        
        while (st <= end) {
            int mid = st + (end - st)/2;
            if (isPossible(arr, n, mid, k)) {
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