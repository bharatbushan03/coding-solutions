/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  private:
    void inOrder(Node* root, int &prev, int &min_diff) {
        if (!root) return;

        // Traverse left subtree
        inOrder(root->left, prev, min_diff);

        // Process current node
        if (prev != -1) {
            min_diff = min(min_diff, root->data - prev);
        }
        prev = root->data; // Update previous node value

        // Traverse right subtree
        inOrder(root->right, prev, min_diff);
    }

  public:
    int absDiff(Node *root) {
        int prev = -1;
        int min_diff = INT_MAX;

        inOrder(root, prev, min_diff);

        return min_diff;
    }
};