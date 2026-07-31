class Solution {
  public:
    int firstIndex(vector<int> &arr) {
        int n = arr.size();
        if (arr[n-1] == 0) return -1;
        
        int st = 0, end = n-1;
        
        while (st <= end) {
            int mid = st + (end - st)/2;
            if (arr[mid] == 1) end = mid - 1;
            else st = mid + 1;
        }
        
        return st;
    }
};