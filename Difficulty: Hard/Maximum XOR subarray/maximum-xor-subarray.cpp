//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


//User function Template for C++


class TrieNode {
public:
    TrieNode* children[2];

    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie () {
        root = new TrieNode();
    }

    void insert (int num) {
        TrieNode* current = root;
        
        for(int i=30; i>=0; i--) {
            int bit = (num >> i) & 1;
            
            if(current->children[bit] == nullptr) {
                current->children[bit] = new TrieNode();
            }
            current = current->children[bit];
        }
    }
    
    int maxXOR (int num) {
        TrieNode* current = root;
        int result = 0;
        
        for(int i=30; i>=0; i--) {
            int bit = (num >> i) & 1;
            
            if(current->children[1-bit] != nullptr) {
                result |= (1<<i);
                current = current->children[1-bit];
            } else {
                current = current->children[bit];
            }
        }
        return result;
    }

};


class Solution{   
public:
    int maxSubarrayXOR(int N, int arr[]){    
        //code here
        Trie trie;
        
        int prefixSum = 0;
        int maxsub = 0;
        
        trie.insert(0);
        
        for(int i=0; i<N; i++) {
            prefixSum ^= arr[i];
            trie.insert(prefixSum);
            maxsub = max(maxsub, trie.maxXOR(prefixSum));
        }
        
        return maxsub;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 

// } Driver Code Ends