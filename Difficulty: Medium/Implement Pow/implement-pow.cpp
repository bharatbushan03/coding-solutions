class Solution {
  public:
    double power(double x, int n) {
        double ans = 1;
        bool negi = n < 0;
        long long m = n;
        m = abs(m);
        while (m > 0) {
            if (m%2 == 0) {
                m = m/2;
                x = x * x;
            }
            else {
                m--;
                ans = ans*x;
            }
        }

        return negi ? 1/ans : ans;
    }
};