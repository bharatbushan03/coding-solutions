class Solution {
public:
    string compress(string s) {
        int n = s.length();
        if (n == 0) return "";

        // 1. Build KMP LPS array
        vector<int> lps(n, 0);
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = lps[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            lps[i] = j;
        }

        // 2. Greedy decompression in reverse
        string res = "";
        int i = n - 1;

        while (i >= 0) {
            if (i % 2 == 1) {
                int half = (i + 1) / 2;
                int k = lps[i];

                // Reduce k if it exceeds the half length
                while (k > half) {
                    k = lps[k - 1];
                }

                // Check if the first half exactly repeats in the second half
                if (k == half) {
                    res.push_back('*');
                    i = half - 1;
                    continue;
                }
            }

            res.push_back(s[i]);
            i--;
        }

        // 3. Reverse to get final answer
        reverse(res.begin(), res.end());
        return res;
    }
};