class Solution {
private:
    int maxLen;
    
    int dfs(Node* root) {
        if (!root) return 0;
        
        int leftLen = 1;
        int rightLen = 1;
        
        if (root->left) {
            int leftSub = dfs(root->left);
            if (root->left->data == root->data + 1) {
                leftLen += leftSub;
            }
        }
        
        if (root->right) {
            int rightSub = dfs(root->right);
            if (root->right->data == root->data + 1) {
                rightLen += rightSub;
            }
        }
        
        int currentMax = max(leftLen, rightLen);
        maxLen = max(maxLen, currentMax);
        
        return currentMax;
    }

public:
    int longestConsecutive(Node* root) {
        if (!root) return -1;
        maxLen = 0;
        dfs(root);
        // If maxLen is 1, it means no consecutive sequence of length > 1 exists
        return maxLen > 1 ? maxLen : -1;
    }
};