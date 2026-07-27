class Solution {
  public:
    int calculate(vector<int>& arr, int sum) {
        if (sum < 0) return 0;
        int n = arr.size();
        int ans = 0;
        int l=0, r=0;
        int currsum = 0;

        while (r < n) {
            currsum += arr[r];
            while (l <= r && currsum > sum) currsum -= arr[l++];
            ans += (r-l+1);
            r++;
        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& arr, int sum) {
        // int n = arr.size();
        // int ans = 0;
        // for (int i=0; i<n; i++) {
        //     int currsum = 0;
        //     for (int j=i; j<n; j++) {
        //         currsum += arr[j];
        //         if (currsum == tar) {
        //             ans++;
        //         }
        //         else if (currsum > tar) break;
        //     }
        // }

        // return ans;
        
        return calculate(arr, sum) - calculate(arr, sum-1);
    }
};