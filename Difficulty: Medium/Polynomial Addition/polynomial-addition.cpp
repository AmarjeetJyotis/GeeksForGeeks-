//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int coeff;
    int pow;
    Node* next;

    Node(int c, int p)
        : coeff(c)
        , pow(p)
        , next(nullptr) {}
};

void append(Node*& head_ref, Node*& tail_ref, int new_data, int new_data1) {
    Node* new_node = new Node(new_data, new_data1);

    if (head_ref == nullptr)
        head_ref = new_node;
    else
        tail_ref->next = new_node;
    tail_ref = new_node;
}

void printList(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->coeff << "x^" << temp->pow;
        if (temp->next != nullptr)
            cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}


// } Driver Code Ends


/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;

    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
};
*/

class Solution {
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    
        
    Node *addPolynomial(Node *head1, Node *head2) {
        // Your code here
        Node* temp1=head1;
        Node* temp2=head2;
        Node* ans=NULL;
        Node* head=NULL;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->pow==temp2->pow){
                Node* newNode =new Node(temp1->coeff + temp2->coeff, temp1->pow);
                if(ans==NULL){
                    head=newNode;
                    ans=newNode;
                }
                else{
                    ans->next=newNode;
                    ans=ans->next;
                }
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if(temp1->pow >temp2->pow){
                Node* newNode =new Node(temp1->coeff, temp1->pow);
                if(ans==NULL){
                    head=newNode;
                    ans=newNode;
                }
                else{
                    ans->next=newNode;
                    ans=ans->next;
                }
                temp1=temp1->next;
            }
            else if(temp1->pow<temp2->pow){
                 Node* newNode =new Node(temp2->coeff, temp2->pow);
                if(ans==NULL){
                    head=newNode;
                    ans=newNode;
                }
                else{
                    ans->next=newNode;
                    ans=ans->next;
                }
                temp2=temp2->next;
            }

        }
        while(temp1!=NULL){
                Node* newNode =new Node(temp1->coeff, temp1->pow);
                    ans->next=newNode;
                    ans=ans->next;
                temp1=temp1->next;
            }
            while(temp2!=NULL){
                Node* newNode =new Node(temp2->coeff, temp2->pow);
              
                
                    ans->next=newNode;
                    ans=ans->next;
                
                temp2=temp2->next;
            }
        ans->next=NULL;
        ans=head;
        return ans;
    }
};




//{ Driver Code Starts.

/* Driver program to test above function */
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr1;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        Node *poly1 = nullptr, *poly2 = nullptr, *tail1 = nullptr, *tail2 = nullptr;
        int n = arr1.size();
        for (int i = 0; i < n; i += 2) {
            int x = arr1[i], y = arr1[i + 1];
            append(poly1, tail1, x, y);
        }

        vector<int> arr2;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss1(input);
        while (ss1 >> number) {
            arr2.push_back(number);
        }

        int m = arr2.size();
        for (int i = 0; i < m; i += 2) {
            int x = arr2[i], y = arr2[i + 1];
            append(poly2, tail2, x, y);
        }

        Solution obj;
        Node* sum = obj.addPolynomial(poly1, poly2);
        printList(sum);
    }

    return 0;
}

// } Driver Code Ends