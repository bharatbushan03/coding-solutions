/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    void Find(Node* root, int pos, int& l) {
        if (!root) return;
        l = max(l, pos);
        
        Find(root->left, pos+1, l);
        Find(root->right, pos, l);
    }
    
    void FindDiag(Node* root, int pos, vector<vector<int>>& temp) {
        if (!root) return;
        temp[pos].push_back(root->data);
        FindDiag(root->left, pos+1, temp);
        FindDiag(root->right, pos, temp);
    }
    
    vector<int> diagonal(Node *root) {
        int l=0;
        Find(root, 0, l);
        vector<vector<int>> temp(l+1);
        FindDiag(root, 0, temp);
        
        vector<int> ans;
        
        for (int i=0; i<l+1; i++) {
            for (int j=0; j<temp[i].size(); j++) {
                ans.push_back(temp[i][j]);
            }
        }
        
        return ans;
    }
};