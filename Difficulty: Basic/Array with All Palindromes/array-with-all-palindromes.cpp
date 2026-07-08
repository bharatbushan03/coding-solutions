class Solution {
  public:
    bool isPalin(int n) {
        int val = n, num = 0;
        while (val) {
            num = num*10 + val%10;
            val = val/10;
        }
        return n == num;
    }
    bool isPalinArray(vector<int> &arr) {
        for (auto i : arr) {
            if (!isPalin(i)) return false;
        }
        
        return true;
    }
};