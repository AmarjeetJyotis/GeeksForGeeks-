//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends


//User function Template for C++

//User function Template for C++
class Solution{
public:
    int maxDifferenceBST(Node *root, int target){
        
        int rootToTargetSum = 0;
        
        Node* targetNode = findTargetNode(root, target, rootToTargetSum);
        
        if (targetNode == nullptr) return -1;
        
        int targetToLeafSum = findMinPathSum(targetNode, 0);
        
        return rootToTargetSum - (targetToLeafSum - targetNode->data);
    }
    
private:
    
    Node* findTargetNode(Node* root, int target, int& sum) {
        if (root == nullptr) return nullptr;
        
    
        if (root->data == target) {
            return root;
        }
        
        if (target < root->data) {
            sum += root->data;  
            return findTargetNode(root->left, target, sum);
        }
        
    
        if (target > root->data) {
            sum += root->data;  
            return findTargetNode(root->right, target, sum);
        }
        
        return NULL; 
    }
    
    
    int findMinPathSum(Node* root, int currentSum) {
        if (root == nullptr) {
            return INT_MAX;
        }
        
        currentSum += root->data;
        
        if (root->left == nullptr && root->right == nullptr) {
            return currentSum;
        }
        
        int leftSum = findMinPathSum(root->left, currentSum);
        int rightSum = findMinPathSum(root->right, currentSum);
        
        return min(leftSum, rightSum);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends