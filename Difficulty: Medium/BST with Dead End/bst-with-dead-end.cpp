/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
  
    bool helper(Node* root , int left , int right){
        if(!root) return false;
        if(root -> data == left && root -> data == right) return true;
        
        return helper(root->left,left,root->data-1) || helper(root->right,root->data+1,right);
    }
    
    bool isDeadEnd(Node *root) {
        return helper(root,1,INT_MAX);
        
    }
};
