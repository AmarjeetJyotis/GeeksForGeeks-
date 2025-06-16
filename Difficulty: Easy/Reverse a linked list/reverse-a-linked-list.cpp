/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
  
  
  Node* reverse(Node* &prev, Node* &curr){
      if(curr==NULL){
          return prev;
      }
      // one case
      Node* right=curr->next;
      curr->next=prev;
      
      // recursion call
      return reverse(curr, right);
  }
    Node* reverseList(struct Node* head) {
        // code here
        Node* prev=NULL;
        Node* curr=head;
        return reverse(prev, curr);
    }
};