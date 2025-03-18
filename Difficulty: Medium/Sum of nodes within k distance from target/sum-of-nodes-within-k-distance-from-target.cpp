//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends


/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution{
public:
    unordered_map<Node*,Node*>mp;
    void inorder(Node* root,Node* &pre,int target)
    {
        if(!root)return;
        if(root->left)
        {
            mp[root->left]=root;
        }
        if(root->data==target)
        {
            pre=root;
        }
        inorder(root->left,pre,target);
        if(root->right){
            mp[root->right]=root;
        }
        inorder(root->right,pre,target);
        
    }
    void bfs(Node* root,int target,int k,int &sum,Node* pre)
    {
        queue<Node*>q;
        q.push(pre);
        sum=sum+pre->data;
        queue<Node*>use;
        unordered_set<int>s;
        s.insert(pre->data);
        
        while(!q.empty())
        {
            int n=q.size();
            if(k==0)break;
            while(n--)
            {
                Node* temp=q.front();
                q.pop();
                if(temp->left&&!s.count(temp->left->data))
                {
                    q.push(temp->left);
                    use.push(temp->left);
                    s.insert(temp->left->data);
                }
                if(temp->right&&!s.count(temp->right->data))
                {
                    q.push(temp->right);
                    use.push(temp->right);
                    s.insert(temp->right->data);
                }
                if(mp.count(temp)&&!s.count(mp[temp]->data))
                {
                    q.push(mp[temp]);
                    use.push(mp[temp]);
                    s.insert(mp[temp]->data);
                }
                
            }
            while(!use.empty())
            {
                sum=sum+use.front()->data;
                use.pop();
            }
            k--;
        }
    }
    int sum_at_distK(Node* root, int target, int k)
    {
           Node* pre;
        inorder(root,pre,target);
     
        int sum=0;
        bfs(root,target,k,sum,pre);
        return sum;
    }
};





//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        
        Solution ob;
        cout<< ob.sum_at_distK(root,target,k) << endl;
    
cout << "~" << "\n";
}
	return 0;
}


// } Driver Code Ends