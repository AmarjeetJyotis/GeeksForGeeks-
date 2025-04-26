//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

// User Function template for C++

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
int height(Node* tree)
{
    if(tree==NULL)
     return 0;
     
     int left=height(tree->left);
     int right=height(tree->right);
     return 1+max(left,right);
}
class Solution {
  public:
    bool isHeap(Node* tree) {
        // code here
        int length=height(tree);
        //cout<<length<<endl;
        queue<Node*>q;
        q.push(tree);
        while(!q.empty())
        {
            length--;
            int level=q.size();
            int x=q.front()->data;
            int flag2=0;
            Node* fro=q.front();
            if(level>0 && length>1){
                //cout<<length<<endl;
                if(fro->left!=NULL && fro->right!=NULL)
                 flag2=1;
            }
            else
            flag2=1;
            for(int i=0;i<level;i++){
                Node* fro=q.front();
                q.pop();
                int flag=0;
                if(fro->left!=NULL)
                {
                    if(flag==0 && flag2==1)
                    flag=1;
                    else{
                        // //cout<<flag<<"  "<<flag2<<endl;
                        // //cout<<"1"<<endl;
                    return false;
                    }
                    q.push(fro->left);
                    if(fro->left->data>=x){
                        // //cout<<"2"<<endl;
                     return false;
                    }
                }
            
              if(fro->right!=NULL)
                {
                    if(flag==0){
                        //cout<<"3"<<endl;
                     return false;
                    }
                    q.push(fro->right);
                    if(fro->right->data>=x){
                        //cout<<"4"<<endl;
                     return false;
                    }
                }
                if(fro->left==NULL || fro->right==NULL)
                 flag2=0;
              
            }
        }
        return true;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends