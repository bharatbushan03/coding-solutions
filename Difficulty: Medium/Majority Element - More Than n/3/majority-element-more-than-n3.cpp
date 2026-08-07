class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        int cnt1=0, cnt2=0;
        int el1=INT_MIN, el2=INT_MIN;
        for (int i=0; i<n; i++) {
            if (cnt1 == 0 && arr[i] != el2) {
                cnt1 = 1;
                el1 = arr[i];
            }
            else if (cnt2 == 0 && arr[i] != el1) {
                cnt2 = 1;
                el2 = arr[i];
            }
            else if (arr[i] == el1) cnt1++;
            else if (arr[i] == el2) cnt2++;
            else cnt1--, cnt2--;
        }
        cnt1=0;cnt2=0;
        for (int i=0; i<n; i++) {
            if (arr[i] == el1) cnt1++;
            if (arr[i] == el2) cnt2++;
        }
        int mini = (n/3)+1;
        vector<int> ans;
        if (mini <= cnt1) ans.push_back(el1);
        if (mini <= cnt2) ans.push_back(el2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};