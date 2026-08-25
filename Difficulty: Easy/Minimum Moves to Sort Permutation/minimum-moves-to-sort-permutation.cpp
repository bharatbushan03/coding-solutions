class Solution {
  public:
int minMoves(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;

    // pos[x] stores the index where value x appears
    std::vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        pos[arr[i]] = i;
    }

    int max_len = 1;
    int cur_len = 1;

    for (int val = 1; val < n; ++val) {
        if (pos[val + 1] > pos[val]) {
            cur_len++;
        } else {
            cur_len = 1;
        }
        max_len = std::max(max_len, cur_len);
    }

    return n - max_len;
}
};