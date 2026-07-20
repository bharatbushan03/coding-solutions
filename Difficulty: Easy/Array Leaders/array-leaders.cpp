class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        ans.push_back(arr[n-1]);
        
        for (int i=n-2; i>=0; i--) {
            if (ans.back() <= arr[i]) ans.push_back(arr[i]);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};