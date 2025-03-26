//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends


//Back-end complete function Template for C++

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution{
    public:
    
      int find( int inorder[],int target, int start, int end){
       for(int i=start; i<=end; i++){
           if(inorder[i]==target)return i;
       }
       return -1;
   }
   
  
  
   Node * tree( int inorder[],int preorder[],int instart,int inend,int index){
       if(instart>inend)return nullptr;
       Node* root = new Node(preorder[index]);
       int pos = find(inorder,preorder[index],instart,inend);
       if(pos==-1)return nullptr;
       root->left = tree(inorder,preorder, instart,pos-1,index+1);
       root->right = tree(inorder,preorder,pos+1,inend,index+(pos-instart)+1);
       return root;
   }
    
     void postor(Node* root, vector<int>&post){
         if(!root)return ;
         postor(root->left,post);
         postor(root->right,post);
         post.push_back(root->data);
     }
    
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
    	// Your code goes here
    	   int instart =0;
        int inend = N - 1;
        int index =0;
        Node* root =tree(inorder,preorder,instart,inend,index);
      if( !root)return false;
      
      vector<int>post;
      postor(root,post);
      for(int i=0 ; i<post.size();i++){
          if(postorder[i]!= post[i])return false;
      }
      return true;
    	
    } 

};




//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	
cout << "~" << "\n";
} 
	return 0; 
} 


// } Driver Code Ends