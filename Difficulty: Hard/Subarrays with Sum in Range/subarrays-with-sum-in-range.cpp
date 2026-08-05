class Solution {
  public:
    // Function to count valid prefix sum pairs using merge sort
    int mergeSort(vector<long long> &prefix, int left, int right, int l, int r)
    {
        // Base case
        if (right - left <= 1)
            return 0;
    
        int mid = left + (right - left) / 2;
    
        // Count valid pairs in left and right halves
        int cnt = mergeSort(prefix, left, mid, l, r) +
        mergeSort(prefix, mid, right, l, r);
    
        int low = mid;
        int high = mid;
    
        // Count valid pairs across the two halves
        for (int i = left; i < mid; i++)
        {
            // Find the first prefix sum satisfying
            // prefix[low] - prefix[i] >= l
            while (low < right && prefix[low] - prefix[i] < l)
                low++;
    
            // Find the first prefix sum satisfying
            // prefix[high] - prefix[i] > r
            while (high < right && prefix[high] - prefix[i] <= r)
                high++;
    
            // Add the number of valid prefix sums
            cnt += (high - low);
        }
    
        // Merge the two sorted halves
        vector<long long> temp;
        int i = left, j = mid;
    
        while (i < mid && j < right)
        {
            if (prefix[i] <= prefix[j])
                temp.push_back(prefix[i++]);
            else
                temp.push_back(prefix[j++]);
        }
    
        // Copy the remaining elements of the left half
        while (i < mid)
            temp.push_back(prefix[i++]);
    
        // Copy the remaining elements of the right half
        while (j < right)
            temp.push_back(prefix[j++]);
    
        // Copy the merged array back to the prefix sum array
        for (int k = 0; k < temp.size(); k++)
            prefix[left + k] = temp[k];
    
        return cnt;
    }
    
    // Function to count subarrays having sum in the range [l, r]
    int countSubarray(vector<int> &arr, int l, int r)
    {
        int n = arr.size();
    
        // Compute the prefix sum array
        vector<long long> prefix(n + 1, 0);
    
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + arr[i];
    
        // Count valid prefix sum pairs
        return mergeSort(prefix, 0, n + 1, l, r);
    }
};