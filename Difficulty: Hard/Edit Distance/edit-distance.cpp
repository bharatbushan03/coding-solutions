class Solution {
  public:
    int editDistance(string& s1, string& s2) {
        int m = s1.length();
        int n = s2.length();

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int j = 0; j <= n; j++) {
            prev[j] = j;
        }

        for (int i = 1; i <= m; i++) {
            curr[0] = i;
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = 1 + min({
                        curr[j - 1],   // Insert
                        prev[j],       // Remove
                        prev[j - 1]    // Replace
                    });
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};