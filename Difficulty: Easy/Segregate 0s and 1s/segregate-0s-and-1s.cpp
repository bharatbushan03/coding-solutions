class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int count0 = 0, count1 = 0;
        for (auto i : arr) {
            if (i == 0) count0++;
            if (i == 1) count1++;
        }
        for (auto& i: arr) {
            if (count0) {
                i = 0;
                count0--;
            }
            else i = 1;
        }
    }
};