class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c-'a']++;
        }
        char res;
        int max = 0;
        for (int i=0; i<26; i++) {
            if (freq[i] > max) res = char(i+'a'), max = freq[i];
        }
        return res;
    }
};