//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends


// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    bool book[20011];
    int less[20011];
    int more[20011];
    
    int getPrime(int &x){
        if(x == 1) return 2;
        if(x-less[x] <= more[x]-x) return less[x];
        return more[x];
    }
    
    Node *primeList(Node *head) {
        for(int i=2;i<=20000;i++){
            if(!book[i]){
                for(int j=i+i;j<=20000;j+=i) book[j]=1;
            }
        }
        
        for(int i = 2; i <= 20000; i++){
            if(!book[i]) less[i] = i;
            else less[i]=less[i-1];
        }
        
        for(int i = 20000; i >= 1; i--){
            if(!book[i]) more[i] = i;
            else more[i] = more[i+1];
        }
        
        Node *p = head;
        while(p){
            p->val = getPrime(p->val);
            p = p -> next;
        }
        
        return head;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends