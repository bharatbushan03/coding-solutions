class Solution {
  public:
    int longestSubstr(string& s, int k) {
        int n = s.length();
        int arr[26] = {0};
        int maxlen = 0;
        int maxfreq = 0;

        int r=0, l=0;

        while (r < n) {
            arr[s[r] - 'A']++;
            maxfreq = max(maxfreq, arr[s[r] - 'A']);
            if ((r-l+1) - maxfreq > k) {
                arr[s[l] - 'A']--;
                l++;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }

        return maxlen;
    }
};