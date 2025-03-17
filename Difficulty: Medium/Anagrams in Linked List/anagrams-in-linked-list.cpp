//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    string input;
    getline(cin, input); // Read the entire line input

    stringstream ss(input);
    char ch;
    struct Node *head = NULL, *tail = NULL;

    while (ss >> ch) {
        // cout<< ch << " ";
        if (head == NULL) {
            head = new Node(ch);
            tail = head;

        } else {
            tail->next = new Node(ch);
            tail = tail->next;
        }
    }
    // cout<<endl;

    return head;
}


// } Driver Code Ends


/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(Node* head, string s) 
    {
        deque<Node*>q;
        vector<int>v(26,0),v1(26,0);
        int n=s.size();
        vector<Node*>ans;
        for(int i=0;i<s.size();i++)
        {
            v[s[i]-'a']++;
        }
        Node*curr=head;
        while(curr!=NULL)
        {
            Node*star=curr->next;
            q.push_back(curr);
            v1[curr->data-'a']++;
            bool bl=true;
            for(int i=0;i<26;i++)
            {
                if(v[i]!=v1[i])bl=false;
            }
            if(bl&&q.size()==n)
            {
                Node*res=q.front();
                Node*store=res;
                v1[store->data-'a']--;
                q.pop_front();
                while(q.size()>0)
                {
                    Node*val=q.front();
                    v1[val->data-'a']--;
                    store->next=val;
                    store=val;
                    q.pop_front();
                }
                store->next=NULL;
                ans.push_back(res);
            }
            if(q.size()==n)
            {
                Node*first=q.front();
                v1[first->data-'a']--;
                q.pop_front();
            }
            curr=star;
        }
        return ans;
    }
};




//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the number of test cases

    while (t--) {
        struct Node *head = inputList();

        string s;
        getline(cin, s); // Read the string for the anagram check
        // cout<< s << endl;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0)
            cout << "-1\n";
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends