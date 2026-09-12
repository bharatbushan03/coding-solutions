class Solution {
  private:
    bool isPossible(vector<int>& arr, int n, int mid, int k) {
        int cows=1, last = arr[0];
        for (int i=1; i<n; i++) {
            if (arr[i] - last >= mid) {
                cows++;
                last = arr[i];
            }
            if (cows == k) return true;
        }
        
        return false;
    }
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = -1;
        
        int st=1, end = *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end());
        
        while (st <= end) {
            int mid = st + (end - st)/2;
            if (isPossible(arr, n, mid, k)) {
                ans = mid;
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return ans;
    }
};