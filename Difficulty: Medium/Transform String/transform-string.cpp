class Solution {
  public:
    int transform(string &s1, string &s2) {

        if (s1.length() != s2.length()) {
            return -1;
        }

        // Create a map to store the frequency of characters in string s1
        unordered_map<char, int> m;
        int n = s1.length();
        for (int i = 0; i < n; i++) {

            // If the character already exists in the map
            if (m.count(s1[i])) 
                m[s1[i]]++;

            // Add the character to the map with a frequency of 1
            else
                m[s1[i]] = 1;
        }

        // Subtract the frequency of characters in string s2 from the map
        for (int i = 0; i < n; i++) {
            if (m.count(s2[i]))
                m[s2[i]]--;
        }

        // Check if all frequencies are 0 to verify strings are anagrams
        for (auto it : m) {
            if (it.second != 0) 
                return -1;
        }

        // Calculate minimum operations using a greedy right-to-left approach
        int i = n - 1, j = n - 1;
        int res = 0;
        while (i >= 0 && j >= 0) {

            // If characters mismatch, s1[i] must be moved to the front
            while (i >= 0 && s1[i] != s2[j]) {

                // Increment the number of operations required
                res++;

                // Move pointer i to the left to find a match for s2[j]
                i--;
            }

            // Move both pointers if a match is found or i is exhausted
            i--;
            j--;
        }

        return res;
    }
};
