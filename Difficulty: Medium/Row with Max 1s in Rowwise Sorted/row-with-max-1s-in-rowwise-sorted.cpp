class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int m = arr.size(), n = arr[0].size();
        int ans = 0, idx = -1;
        
        for (int i=0; i<m; i++) {
            int st=0, end = n - 1;
            while (st <= end) {
                int mid = st + (end - st)/2;
                if (arr[i][mid] == 1) {
                    if (n - mid > ans) {
                        ans = n - mid;
                        idx = i;
                    }
                    end = mid - 1;
                }
                else {
                    st = mid + 1;
                }
            }
        }
        
        return idx;
    }
};