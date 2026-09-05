class Solution {
  public:
    int upperBound(vector<int>& arr, int tar) {
        int n = arr.size();
        int st = 0, end = n-1;
        while (st <= end) {
            int mid = st + (end - st)/2;
            if (arr[mid] > tar) end = mid - 1;
            else st = mid + 1;
        }
        return st;
    }
};
