class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        vector<int> arr;
        int i=0, j=0;
        
        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) {
                arr.push_back(a[i++]);
            }
            else arr.push_back(b[j++]);
        }
        
        while (i < a.size()) {
            arr.push_back(a[i++]);
        }
        
        while (j < b.size()) {
            arr.push_back(b[j++]);
        }
        
        if (arr.size()%2 == 0) {
            return double(arr[arr.size()/2] + arr[arr.size()/2-1])/2;
        }
        
        return double(arr[(arr.size())/2]);
        
    }
};