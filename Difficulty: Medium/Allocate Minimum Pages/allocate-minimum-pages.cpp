class Solution {
  public:
    bool isPossible(vector<int>& arr, long long k, long long mid) {
        long long pgs = 0, students = 1;
        for (int i : arr) {
            if (pgs + i <= mid) pgs += i;
            else pgs = i, students++;
        }
        
        return students <= k;
    }
    
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;
        int ans = -1;
        
        long long st = *max_element(arr.begin(), arr.end()), end = accumulate(arr.begin(), arr.end(), 0LL);
        
        while (st <= end) {
            long long mid = st + (end - st)/2;
            if (isPossible(arr, (long long)k, mid)) {
                ans = (int)mid;
                end = mid - 1;
            }
            else st = mid + 1;
        }
        
        return ans;
    }
};