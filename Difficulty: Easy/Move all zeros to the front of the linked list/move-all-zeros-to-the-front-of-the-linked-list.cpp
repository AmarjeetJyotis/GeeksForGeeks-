//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to display nodes
void display(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


// } Driver Code Ends

// User function Template for C++
/* Linked List Node structure
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
  public:
    void moveZeroes(struct Node*& head) {
        // code here
        Node *h1=head;
        Node *a=new Node(-1);
        Node *b=new Node(-1);
        Node *zero=a;
        Node *notzero=b;
        
        //  cout<<h1->data<<endl;
        // zero->next=NULL;
        while(h1!=NULL){
            if(h1->data==0){
                zero->next=h1;
                zero=zero->next;
            }
            else {
                notzero->next=h1;
                notzero=notzero->next;
            }
            h1=h1->next;
        }
         zero->next=b->next;
         notzero->next=NULL;
       
        
        head=a->next;
        delete a;
        delete b;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t
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
        ob.moveZeroes(head);
        display(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends