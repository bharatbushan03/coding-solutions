class Solution {
  private:
    bool isFound(vector<vector<int>>& arr, int mid, int x) {
        int m = arr.size(), n = arr[0].size();
        int st = 0, end = n-1;
        while (st <= end) {
            int midR = st + (end - st)/2;
            if (arr[mid][midR] == x) return true;
            else if (arr[mid][midR] > x) end = midR - 1;
            else st = midR + 1;
        }
        
        return false;
    }
  public:
    bool searchMatrix(vector<vector<int>> &arr, int x) {
        int m = arr.size(), n = arr[0].size();
        
        int st = 0, end = m - 1;
        while (st <= end) {
            int mid = st + (end - st)/2;
            if (arr[mid][0] <= x && arr[mid][n-1] >= x) {
                return isFound(arr, mid, x);
            }
            else if (arr[mid][0] > x) end = mid - 1;
            else st = mid + 1;
        }
        
        return false;
    }
};