class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        if (arr.size() == 0 || arr.size() == 1) return -1;
        int maxi = arr[0];
        int smaxi = -1;
        for (auto i : arr) {
            if (i > maxi) {
                smaxi = maxi;
                maxi = i;
            }
            else if (smaxi < i and i < maxi) smaxi = i;
        }
        
        return smaxi;
    }
};