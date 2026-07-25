class Solution {
  public:
    int countSubstring(string &s) {
        int n = s.length();
        int ans = 0;

        for (int i=0; i<n; i++) {
            bool a=false, b=false, c=false;
            for (int j=i; j<n; j++) {
                if (s[j] == 'a') a=true;
                else if (s[j] == 'b') b=true;
                else if (s[j] == 'c') c=true;

                if (a && b && c) {
                    ans += n-j;
                    break;
                }
            }
        }

        return ans;
    }
};