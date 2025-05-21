/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
class Solution {
  public:
  int help(Node *head){
      Node *temp=head;
      int count=0;
      while(temp){
          count++;
          temp=temp->next;
      }
      return count;
  }
    Node* intersectPoint(Node* head1, Node* head2) {
      int cnt1=help(head1);
      int cnt2=help(head2);
     if(cnt2>cnt1) swap(head1,head2) ,swap(cnt2,cnt1);
     
     int diff=cnt1-cnt2;
    
     while(diff--){
         head1=head1->next;
     }
     while(head1 && head2){
         head1=head1->next;
         head2=head2->next;
         if(head1==head2) return head1;
     }
     
     return false;
     
     
      
    }
};

