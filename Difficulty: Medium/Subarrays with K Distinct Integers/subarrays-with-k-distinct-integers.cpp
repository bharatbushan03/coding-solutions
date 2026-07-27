class Solution {
  public:
    int calculate(vector<int>& arr, int k) {
        int n = arr.size();
        if (k <= 0) return 0;

        int ans = 0;
        int r=0, l=0;
        unordered_map<int, int> m;

        while (r < n) {
            m[arr[r]]++;
            while (m.size() > k) {
                m[arr[l]]--;
                if (m[arr[l]] == 0){
                    m.erase(arr[l]);
                }
                l++;
            }
            ans += r-l+1;
            r++;
        }

        return ans;
    }
    int exactlyK(vector<int> &arr, int k) {
        return calculate(arr, k) - calculate(arr, k-1);
    }
};