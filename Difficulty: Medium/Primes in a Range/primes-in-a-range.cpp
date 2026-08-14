class Solution {
  public:
    vector<int> primeRange(int l, int r) {
        vector<bool> primes(r+1, true);
        primes[1] = false;
        for (int i=2; i<=r; i++) {
            for (int j=2*i; j<=r; j=j+i) {
                primes[j] = false;
            }
        }
        vector<int> ans;
        for (int i=l; i<=r; i++) {
            if (primes[i]) ans.push_back(i);
        }
        return ans;
    }
};