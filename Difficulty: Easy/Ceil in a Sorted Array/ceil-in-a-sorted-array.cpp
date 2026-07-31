class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int n = arr.size();
        if (x > arr[n-1]) return -1;
        
        int st = 0, end = n-1;
        
        while (st <= end) {
            int mid = st + (end - st)/2;
            if (arr[mid] < x) st = mid + 1;
            else end = mid - 1;
        }
        
        return st;
    }
};