class Solution {
  public:
    int nthRoot(int n, int m) {
        if (m == 0) return 0;
        for (int i=1; i<=m; i++) {
            int canbe = 1;
            for (int j=0; j<n; j++) canbe*=i;
            if (canbe == m) return i;
        }
        return -1;
    }
};