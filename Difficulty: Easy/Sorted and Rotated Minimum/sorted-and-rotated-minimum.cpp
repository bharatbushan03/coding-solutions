class Solution {
  public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int st = 0, end = n - 1;
        if (n == 1) return arr[0];
        else if (n == 2) return min(arr[0], arr[1]);

        int ans = arr[n-1];

        while (st <= end) {
            int mid = st + (end - st)/2;
            ans = min(ans, arr[mid]);
            if (arr[st] <= arr[mid]) {
                if (arr[st] < arr[end]) end = mid - 1;
                else st = mid + 1;
            }
            else {
                if (arr[st] > arr[end]) end = mid - 1;
                else st = mid + 1;
            }
        }

        return ans;
    }
};