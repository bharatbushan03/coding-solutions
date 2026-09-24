/* Strucutre of a link list node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertInMiddle(Node *head, int x) {
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        if (n == 0) return new Node(x);
        int i = (n-1)/2;
        temp = head;
        while (i > 0) {
            temp = temp->next;
            i--;
        }
        Node* curr = new Node(x);
        curr->next = temp->next;
        temp->next = curr;
        return head;
    }
};