class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();

        if (n == 1 || n == 2) return n;

        int ans = 0;
        int tree1=arr[0], tree2=-1;
        int t1count=1, t2count=0;

        int l=0, r=1;
        int k = 1;

        while (r < n) {
            if (tree2 == -1) {
                if (tree1 == arr[r]) {
                    t1count++;
                }
                else {
                    tree2 = arr[r];
                    t2count++;
                    k++;
                }
            }
            else if (tree1 == arr[r]) t1count++;
            else if (tree2 == arr[r]) t2count++;
            else {
                k++;
                while (k > 2 && l < r) {
                    if (arr[l] == tree1) {
                        t1count--;
                        if (t1count == 0) {
                            k--;
                            tree1 = arr[r];
                            t1count = 1;
                        }
                        l++;
                    }
                    else {
                        t2count--;
                        if (t2count == 0) {
                            k--;
                            tree2 = -1;
                            tree2 = arr[r];
                            t2count = 1;
                        }
                        l++;
                    }
                }
            }
            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};