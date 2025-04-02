//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to insert a node at the end of the Doubly Linked List
void push(DLLNode **headRef, DLLNode **tailRef, int new_data) {
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end, next is NULL
    newNode->next = NULL;

    // change next of tail node to new node
    if ((*tailRef) != NULL) {
        newNode->prev = (*tailRef);
        (*tailRef)->next = newNode;
    } else {
        // if the list is empty
        (*headRef) = newNode;
        newNode->prev = NULL;
    }

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends



/* a Node of the doubly linked list */

/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/





class Solution {
public:
    // Function to find the last node (tail) of the doubly linked list
    DLLNode* getLastNode(DLLNode* head) {
        while (head && head->next)
            head = head->next;
        return head;
    }

    // Partition function for QuickSort
    DLLNode* partition(DLLNode* low, DLLNode* high) {
        int pivot = high->data; // Choose last node as pivot
        DLLNode* i = low->prev; // Pointer for smaller element

        for (DLLNode* j = low; j != high; j = j->next) {
            if (j->data < pivot) {
                i = (i == nullptr) ? low : i->next; // Move i forward
                swap(i->data, j->data);
            }
        }
        i = (i == nullptr) ? low : i->next; // Move i forward
        swap(i->data, high->data); // Swap pivot element with i
        return i; // Return pivot position
    }

    // QuickSort function for Doubly Linked List
    void quickSortHelper(DLLNode* low, DLLNode* high) {
        if (high != nullptr && low != high && low != high->next) {
            DLLNode* pivot = partition(low, high);
            quickSortHelper(low, pivot->prev);  // Sort left half
            quickSortHelper(pivot->next, high); // Sort right half
        }
    }

    // Main QuickSort function
    DLLNode* quickSort(DLLNode* head) {
        if (!head || !head->next) return head; // If empty or single node, return
        
        DLLNode* last = getLastNode(head); // Get tail node
        quickSortHelper(head, last); // Sort the list
        
        return head; // Return sorted head
    }
};  // FIX: Closing brace for Solution class

//{ Driver Code Starts.

// Driver code
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        DLLNode *head = nullptr, *tail = nullptr;
        for (int i = 0; i < arr.size(); i++) {
            push(&head, &tail, arr[i]);
        }

        Solution obj;
        head = obj.quickSort(head);
        printList(head);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends