//Back-end complete function Template for C++

class Solution {
  public:
    int countZeros(vector<vector<int>>& arr) {
        int n = arr.size();
        int count = 0;
        
        for (int i=0; i<n; i++) {
            int st = 0, end = n-1;
            while (st <= end) {
                int mid = st + (end - st)/2;
                if (arr[i][mid] == 1) end = mid - 1;
                else st = mid + 1;
            }
            count += st;
        }
        
        return count;
    }
};