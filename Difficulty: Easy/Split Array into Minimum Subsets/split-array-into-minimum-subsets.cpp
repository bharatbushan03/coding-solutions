class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());    
    
        int count = 0;
        for(int x : arr) {
            // Check for the start of a new subset 
            if(s.find(x - 1) == s.end()) {
                count++;
            }
        }
        return count;
    }
};
