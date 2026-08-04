class Solution {
  public:
    int countPairs(vector<int> &arr, int k)
{
    int n = arr.size();

    // Sort the array in non-decreasing order
    sort(arr.begin(), arr.end());

    int total = 0;
    int s = 0;

    // Iterate with right pointer i
    for (int i = 0; i < n; i++)
    {

        // Shrink the window from the left until
        // the condition holds
        while (arr[i] - arr[s] >= k)
        {
            s++;
        }

        // All elements between's' and 'i-1' form
        // a valid pair with 'arr[i]'
        total += (i - s);
    }

    return total;
}
};