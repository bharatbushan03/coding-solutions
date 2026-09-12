#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int> &arr, int k) {
        int n = arr.size();
        std::sort(arr.begin(), arr.end());

        long long max_prod = 1;

        // Case 1: If the largest element is non-positive and k is odd,
        // we are forced to pick a negative/zero max product.
        if (arr[n - 1] <= 0 && k % 2 != 0) {
            for (int i = n - 1; i >= n - k; i--) {
                max_prod *= arr[i];
            }
            return (int)max_prod;
        }

        int left = 0;
        int right = n - 1;

        // Pick elements in pairs or individually
        while (k > 0) {
            if (k == 1) {
                max_prod *= arr[right];
                break;
            }

            long long left_pair = (long long)arr[left] * arr[left + 1];
            long long right_pair = (long long)arr[right] * arr[right - 1];

            if (left_pair > right_pair) {
                max_prod *= left_pair;
                left += 2;
            } else {
                max_prod *= arr[right];
                right--;
                k++; // We only took 1 element instead of pair, balance k decrease below
            }

            k -= 2;
        }

        return (int)max_prod;
    }
};