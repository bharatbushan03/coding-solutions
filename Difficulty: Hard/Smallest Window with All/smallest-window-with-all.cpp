class Solution {
  public:
    string minWindow(string &s, string &p) {
        unordered_map<char, int> m;
        for (char c : p) m[c]++;
        int i = 0, j = 0, count = 0;
        int n = s.length(), n1 = p.length();
        int minlen = INT_MAX;
        int sIdx = -1;
        
        while (j < n) {
            if (m[s[j]] > 0) count++;
            m[s[j]]--;
            
            while (n1 == count) {
                if (minlen > j-i+1) {
                    minlen = j-i+1;
                    sIdx = i;
                }
                m[s[i]]++;
                if(m[s[i]] == 1) count--;
                i++;
            }
            j++;
            
        }
        if (minlen == INT_MAX) return "";
        string ans = s.substr(sIdx, minlen);
        return ans;
    }
};