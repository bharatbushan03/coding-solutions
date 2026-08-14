class Solution {
  public:
    bool armstrongNumber(int n) {
        int num = n;
        int d = 0;
        while (n) {
            n = n/10;
            d++;
        }
        n = num;
        int ans = 0;
        while (n) {
            ans += pow((n%10), d);
            n = n/10;
        }
        return ans == num;
    }
};