class Solution {
  public:
    int minDeletions(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> lis;
        
        for (int i = 0; i < n; i++) {
            // Use lower_bound to find the first element >= arr[i]
            auto it = std::lower_bound(lis.begin(), lis.end(), arr[i]);
            
            if (it == lis.end()) {
                lis.push_back(arr[i]);
            } else {
                *it = arr[i];
            }
        }
        
        // Minimum deletions = Total elements - Length of Longest Increasing Subsequence
        return n - lis.size();
    }
};