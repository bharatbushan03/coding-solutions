class Solution {
  private:
    int getDigitSum(long long num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

  public:
    int findMax(int n) {
        long long ans = n;
        int max_sum = getDigitSum(n);
        
        long long p = 1; // Power of 10
        long long temp = n;
        
        while (temp > 0) {
            // Modify the current digit position
            long long candidate = (temp - 1) * p + (p - 1);
            
            if (candidate > 0) {
                int current_sum = getDigitSum(candidate);
                
                // If candidate has a larger digit sum, or an equal sum with a larger value
                if (current_sum > max_sum || (current_sum == max_sum && candidate > ans)) {
                    max_sum = current_sum;
                    ans = candidate;
                }
            }
            
            p *= 10;
            temp /= 10;
        }
        
        return ans;
    }
};