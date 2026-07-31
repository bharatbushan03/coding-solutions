
// User function Template for C++

class Solution {
  public:
    bool isValid(vector<int> arr,int n,int mid,int k) {
        int cow=1,lp=arr[0];
        for (int i=1; i<n; i++) {
            if (arr[i]-lp>=mid) {
                cow++;
                lp=arr[i];
            }
            if (cow==k) return true;
        }
        
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        int n=arr.size();
        if (k>n) return -1;
        sort(arr.begin(), arr.end());
        int st=1, end=arr[n-1]-arr[0];
        int ans=-1;
        while (st<=end) {
            int mid=st+(end-st)/2;
            if (isValid(arr,n,mid,k)) {
                ans=mid;
                st=mid+1;
            }
            else {
                end=mid-1;
            }
        }
        
        return ans;
    }
};