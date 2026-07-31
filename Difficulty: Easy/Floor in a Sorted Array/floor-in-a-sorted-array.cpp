class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int n = arr.size();
        if (arr[0] > x) return -1;
        int st = 0, end = n-1;
        
        while (st <= end) {
            int mid = st + (end - st)/2;
            if (arr[mid] > x) end = mid - 1;
            else st = mid + 1;
        }
        
        return end;
    }
};
