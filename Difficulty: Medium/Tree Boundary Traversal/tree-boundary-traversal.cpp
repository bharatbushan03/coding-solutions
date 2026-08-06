/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  private:
    bool isLeaf(Node* root) {
        if (!root->left && !root->right) return true;
        return false;
    }
    void addLeftBoundary(Node* root, vector<int>& ans) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) ans.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    void addRightBoundary(Node* root, vector<int>& ans) {
        Node* curr = root->right;
        stack<int> st;
        while (curr) {
            if (!isLeaf(curr)) st.push(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
    }
    void addLeaves(Node* root, vector<int>& ans) {
        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, ans);
        if (root->right) addLeaves(root->right, ans);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (!root) return ans;
        if (!isLeaf(root)) ans.push_back(root->data);
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);
        return ans;
    }
};