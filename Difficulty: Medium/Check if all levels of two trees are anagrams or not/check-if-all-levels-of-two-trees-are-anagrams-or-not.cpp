//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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


//User function Template for C++

class Solution{
    public:
    unordered_map<int, string> umap1;
    unordered_map<int, string> umap2;
    set<int> levels;
    void traverse1(Node *root, int level){
        if(root == NULL) return;
        traverse1(root->left, level+1);
        umap1[level].push_back(root->data+'0');
        levels.insert(level);
        traverse1(root->right, level+1);
    }
    void traverse2(Node *root, int level){
        if(root == NULL) return;
        traverse2(root->left, level+1);
        umap2[level].push_back(root->data+'0');
        traverse2(root->right, level+1);
    }
    bool areAnagrams(Node *root1, Node *root2)
    {
        umap1.clear();
        umap2.clear();
        levels.clear();
        traverse1(root1, 1);
        traverse2(root2, 1);
        for(auto i : levels){
            if(umap1[i].length() != umap2[i].length()){
                return false;
            }
            sort(umap2[i].begin(), umap2[i].end());
            sort(umap1[i].begin(), umap1[i].end());
            for(int j=0; j<umap1[i].size(); j++){
                if(umap1[i][j] != umap2[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends