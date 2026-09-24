/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    int getCount(Node* head) {
        int n = 0;
        while (head) {
            n++;
            head = head->next;
        }
        
        return n;
    }
};