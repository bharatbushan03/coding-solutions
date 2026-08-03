class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
    
        for (int i=n-1; i>=0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if (!st.empty()) ans[i] = arr[st.top()];
            st.push(i);
        }
        
        return ans;
    }
};