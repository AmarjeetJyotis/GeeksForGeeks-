/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* temp = head;
        Node* prev = NULL;
        Node* add = new Node(data);
        while(temp->next != head && temp->data<data){
            prev = temp;
            temp = temp->next;
        }
        if(temp==head){
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = add;
            add->next = head;
            return add;
        }
        else if(temp->next == head && temp->data<data){
            temp->next = add;
            add->next = head;
            return head;
        }
        add->next = temp;
        prev->next = add;
        return head;
    }

};