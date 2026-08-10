class Solution {
  public:
    vector<vector<int>> multiplyMatrices(vector<vector<int>> &a,
                                         vector<vector<int>> &b) {
        int n = a.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int currele = 0;
                for (int k=0; k<n; k++) {
                    currele += a[i][k]*b[k][j];
                }
                ans[i][j] = currele;
            }
        }
        
        return ans;
    }
};