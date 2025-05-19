//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends

// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        if(head==NULL || head->next==NULL)return {};
       vector<pair<int,int>>pr;
       Node* temp=head;
       int end=1;
       while(temp->next!=NULL)
       { temp=temp->next;
         end++;}
       Node* tempstart=head;
       int start=1;
       while(start<end)
       {   int pairsum= tempstart->data + temp->data;
           if( pairsum > target)
           {
               temp=temp->prev;
               end--;
           }
           else if(pairsum<target)
           {
               tempstart=tempstart->next;
               start++;
           }
           else
           {
               pr.push_back({tempstart->data,temp->data});
              tempstart=tempstart->next;
              temp=temp->prev;
              start++;
              end--;
           }
       }
       return pr;
        
    }


};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends