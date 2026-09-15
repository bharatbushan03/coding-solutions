class Solution {
  private:
    void collectLeafLevels(Node* node, int level, vector<int>& leafLevels) {
        if (!node) return;

        // Check if the current node is a leaf node
        if (!node->left && !node->right) {
            leafLevels.push_back(level);
            return;
        }

        collectLeafLevels(node->left, level + 1, leafLevels);
        collectLeafLevels(node->right, level + 1, leafLevels);
    }

  public:
    int getCount(Node *root, int k) {
        if (!root) return 0;

        vector<int> leafLevels;
        collectLeafLevels(root, 1, leafLevels);

        // Sort costs to greedily pick the cheapest (shallowest) leaf nodes first
        sort(leafLevels.begin(), leafLevels.end());

        int count = 0;
        for (int cost : leafLevels) {
            if (k >= cost) {
                k -= cost;
                count++;
            } else {
                break; // Remaining leaves are too expensive
            }
        }

        return count;
    }
};