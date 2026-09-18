class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        for (auto i : mat) {
            for (int j : i) {
                if (jx == x) return true;
            }
        }
        
        return false;
    }
};