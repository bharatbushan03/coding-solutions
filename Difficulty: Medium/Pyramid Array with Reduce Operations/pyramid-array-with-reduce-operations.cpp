#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int formPyramid(std::vector<int>& arr) {
        int n = arr.size();

        // Total sum of all original stone heights
        long long totalSum = 0;
        for (int x : arr) {
            totalSum += x;
        }

        std::vector<int> left(n, 0);
        std::vector<int> right(n, 0);

        // Compute maximum peak possible bounded by left elements
        left[0] = std::min(arr[0], 1);
        for (int i = 1; i < n; i++) {
            left[i] = std::min(arr[i], left[i - 1] + 1);
        }

        // Compute maximum peak possible bounded by right elements
        right[n - 1] = std::min(arr[n - 1], 1);
        for (int i = n - 2; i >= 0; i--) {
            right[i] = std::min(arr[i], right[i + 1] + 1);
        }

        // Find the maximum height of a pyramid
        long long maxPyramidHeight = 0;
        for (int i = 0; i < n; i++) {
            long long peakHeight = std::min(left[i], right[i]);
            maxPyramidHeight = std::max(maxPyramidHeight, peakHeight);
        }

        // Maximum pyramid sum with peak height h is h^2
        long long maxPyramidSum = maxPyramidHeight * maxPyramidHeight;

        return totalSum - maxPyramidSum;
    }
};