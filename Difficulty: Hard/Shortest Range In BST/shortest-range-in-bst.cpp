//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
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
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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


// User function Template for C++


class Solution {
public:
    pair<int, int> shortestRange(Node *root) {
        if (!root) return {0, 0};

        // Step 1: Level Order Traversal
        vector<vector<int>> levels;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                level.push_back(node->data);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            levels.push_back(level);
        }

        int k = levels.size();  // Number of levels

        // Step 2: Store indices in priority queue (min-heap)
        vector<pair<int, int>> arr; // {value, level}
        for (int i = 0; i < k; i++) {
            for (int val : levels[i]) {
                arr.push_back({val, i});
            }
        }

        // Step 3: Sort the array based on value
        sort(arr.begin(), arr.end());

        // Step 4: Find smallest range using Sliding Window
        unordered_map<int, int> count;
        int l = 0, minRange = INT_MAX;
        pair<int, int> result;
        int uniqueLevels = 0; // Number of levels covered

        for (int r = 0; r < arr.size(); r++) {
            if (count[arr[r].second]++ == 0) uniqueLevels++;

            // Try shrinking the window while it still covers all levels
            while (uniqueLevels == k) {
                int low = arr[l].first, high = arr[r].first;
                if (high - low < minRange) {
                    minRange = high - low;
                    result = {low, high};
                }
                if (--count[arr[l].second] == 0) uniqueLevels--;
                l++; // Shrink the window
            }
        }

        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        pair<int, int> range = obj.shortestRange(root);
        cout << range.first << " " << range.second << "\n";
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends