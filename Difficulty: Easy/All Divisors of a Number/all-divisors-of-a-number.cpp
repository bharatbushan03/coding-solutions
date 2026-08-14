class Solution {
  public:
    vector<int> getDivisors(int n) {
        vector<int> ans;
        ans.push_back(1);
        if (n == 1) return ans;
        stack<int> st;
        for (int i=2; i<=sqrt(n); i++) {
            if (n%i == 0) ans.push_back(i);
            if (n%(n/i) == 0 && n/i != i) st.push(n/i);
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        ans.push_back(n);
        return ans;
    }
};