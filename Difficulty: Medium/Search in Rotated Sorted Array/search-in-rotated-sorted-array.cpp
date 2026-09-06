class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        
        int st = 0, end = n-1;
        
        while (st <= end) {
            int mid = st + (end - st)/2;
            if (arr[mid] == key) return mid;
            else if (arr[st] <= arr[mid]) {
                if (arr[st] <= key && arr[mid] >= key) end = mid - 1;
                else st = mid + 1;
            }
            else {
                if (arr[mid] <= key && key <= arr[end]) st = mid + 1;
                else end = mid - 1;
            }
        }
        
        return -1;
    }
};