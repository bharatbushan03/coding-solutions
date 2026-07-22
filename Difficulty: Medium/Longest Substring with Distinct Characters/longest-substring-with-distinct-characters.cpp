class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        unordered_set<char> st;
        int n = s.length();
        int i=0, j=0;
        
        int ans = 0;
        
        while (j < n) {
            if (st.count(s[j]) == 0) {
                ans = max(ans, j-i+1);
                // m[s[j]]++;
                st.insert(s[j]);
                j++;
            }
            else {
                while (i<j && st.count(s[j]) > 0) {
                    // m[s[i]]--;
                    st.erase(s[i]);
                    i++;
                }
                st.insert(s[j]);
                ans = max(ans, j-i+1);
                j++;
            }
            
        }
        
        return ans;
    }
};
