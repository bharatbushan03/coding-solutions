class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = 0;
        
        int presum = 0;
        unordered_map<int, int> m;
        
        for (int i=0; i<n; i++) {
            presum += arr[i];
            if (m.find(presum) == m.end()) m[presum] = i;
            if (presum == k) maxi = i+1;
            int comp = presum - k;
            if (m.find(comp) != m.end()) maxi = max(maxi, i-m[comp]);
        }
        
        return maxi;
    }
};