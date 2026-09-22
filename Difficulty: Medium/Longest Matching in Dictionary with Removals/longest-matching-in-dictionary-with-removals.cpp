class Solution {
  private:
    // Helper function to check if word is a subsequence of s
    bool isSubsequence(const string &word, const string &s) {
        int i = 0, j = 0;
        int n = s.length();
        int m = word.length();

        while (i < n && j < m) {
            if (s[i] == word[j]) {
                j++;
            }
            i++;
        }

        return j == m;
    }

  public:
    string findLongestWord(string &s, vector<string> &d) {
        // Sort dictionary:
        // 1. Decreasing order of length
        // 2. Lexicographically increasing order for equal lengths
        sort(d.begin(), d.end(), [](const string &a, const string &b) {
            if (a.length() != b.length()) {
                return a.length() > b.length();
            }
            return a < b;
        });

        // Find the first valid subsequence word
        for (const string &word : d) {
            if (isSubsequence(word, s)) {
                return word;
            }
        }

        return "";
    }
};