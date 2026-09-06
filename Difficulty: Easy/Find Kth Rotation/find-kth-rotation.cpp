class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int st = 0, end = n - 1;
        
        int ans = 0;
        
        while (st <= end) {
            int mid = st + (end - st)/2;
            if (arr[st] <= arr[mid]) {
                if (arr[ans] > arr[st]) ans = st;
                st = mid + 1;
            }
            else {
                if (arr[mid] < arr[ans]) ans = mid;
                end = mid - 1;
            }
        }
        
        return ans;
    }
};
