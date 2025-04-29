//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends


/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        Node* dummy = new Node(-1);
        Node* zeroDummy = new Node(-1);
        Node* oneDummy = new Node(-1);
        Node* twoDummy = new Node(-1);
        Node* zeroNode = zeroDummy;
        Node* oneNode = oneDummy;
        Node* twoNode = twoDummy;
        Node* node = head;
        while(node!=NULL){
            Node* newNode = node->next;
            if(node->data==0){
                zeroNode->next = node;
                zeroNode = zeroNode->next;
            }
            else if(node->data==1){
                oneNode->next = node;
                oneNode = oneNode->next;
            }
            else{
                twoNode->next = node;
                twoNode = twoNode->next;
            }
            node->next = NULL;
            node = newNode;
        }
        zeroNode->next = oneNode->next = twoNode->next = NULL;
        if(twoDummy->next!=NULL){
            oneNode->next = twoDummy->next;
        }
        if(oneDummy->next!=NULL){
            zeroNode->next = oneDummy->next;
        }
        if(zeroDummy->next!=NULL){
            dummy->next = zeroDummy->next;
        }
        return dummy->next;
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends