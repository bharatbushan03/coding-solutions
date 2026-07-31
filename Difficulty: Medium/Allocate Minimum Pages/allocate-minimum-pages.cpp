class Solution {
  public:
    bool check(vector<int> &arr, int k, long long pageLimit) {

    // starting from the first student
    int cnt = 1;
    long long pageSum = 0;

    for(int i = 0; i < arr.size(); i++) {

        // if adding the current book exceeds the page
        // limit, assign the book to the next student
        if(pageSum + arr[i] > pageLimit) {
            cnt++;
            pageSum = arr[i];
        }
        else {
            pageSum += arr[i];
        }
    }

    // if books can assigned to less than k students then
    // it can be assigned to exactly k students as well
    return (cnt <= k);
}

int findPages(vector<int> &arr, int k) {

    // if number of students are more than total books
    // then allocation is not possible
    if(k > arr.size())
        return -1;

    // search space for Binary Search
    long long lo = *max_element(arr.begin(), arr.end());
    long long hi = accumulate(arr.begin(), arr.end(), 0LL);
    int res = -1;

    while(lo <= hi) {
        long long mid = lo + (hi - lo) / 2;

        if(check(arr, k, mid)) {
            res = (int)mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    return res;
}
};