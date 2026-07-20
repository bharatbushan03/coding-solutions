class Solution {
  public:
    void rotate(vector<int> &arr) {
        std::rotate(arr.rbegin(), arr.rbegin()+1, arr.rend());
    }
};