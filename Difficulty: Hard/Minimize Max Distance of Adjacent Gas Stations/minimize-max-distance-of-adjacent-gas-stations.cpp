class Solution {
  private:
    int Count(vector<int>& arr, double mid) {
        int cnt = 0;
        for (int i=1; i<arr.size(); i++) {
            int between = (double)(arr[i] - arr[i-1])/mid;
            if ((arr[i] - arr[i-1]) == between*mid) between--;
            
            cnt += between;
        }
        
        return cnt;
    }
  public:
    double minMaxDist(vector<int> &arr, int k) {
        int n = arr.size();
        double st=0, end=0;
        for (int i=0; i<n-1; i++) {
            end = max(end, double(arr[i+1] - arr[i]));
        }
        
        double diff = 1e-6;
        while (end - st > diff) {
            double mid = st + (end - st)/2.0;
            int cnt = Count(arr, mid);
            if (cnt > k) st = mid;
            else end = mid;
        }
        
        return abs(end);
    }
};