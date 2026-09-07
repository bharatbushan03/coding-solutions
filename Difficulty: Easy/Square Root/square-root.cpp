class Solution {
  public:
    int floorSqrt(int x) {
        if (x == 1) return x;
        int st = 1, end = x/2;
        while (st <= end) {
            int mid = st + (end - st)/2;
            if (mid == x/mid) return mid;
            else if (mid < x/mid) st = mid + 1;
            else end = mid - 1;
        }

        return end;
    }
};