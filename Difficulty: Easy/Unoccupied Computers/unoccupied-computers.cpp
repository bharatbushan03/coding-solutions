class Solution {
  public:
    int solve(int n, string s) {
        vector<bool> seen(26, false);
        vector<bool> hasComputer(26, false);

        int available = n;
        int rejected = 0;

        for (char c : s) {
            int id = c - 'A';

            if (!seen[id]) {
                // Customer arrives
                seen[id] = true;

                if (available > 0) {
                    hasComputer[id] = true;
                    available--;
                } else {
                    rejected++;
                }
            } else {
                // Customer leaves
                if (hasComputer[id]) {
                    available++;
                    hasComputer[id] = false;
                }
            }
        }

        return rejected;
    }
};