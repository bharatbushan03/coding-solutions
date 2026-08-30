class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        int n = l.size();
        std::vector<long long> pref(n);
        
        pref[0] = r[0] - l[0] + 1;
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + (r[i] - l[i] + 1);
        }
        
        std::vector<int> result;
        result.reserve(rank.size());
        
        for (int k : rank) {
            // Find the interval containing the k-th rank
            int idx = std::lower_bound(pref.begin(), pref.end(), (long long)k) - pref.begin();
            
            long long prev_count = (idx > 0) ? pref[idx - 1] : 0;
            long long offset = k - prev_count - 1;
            
            result.push_back(l[idx] + offset);
        }
        
        return result;
    }
};