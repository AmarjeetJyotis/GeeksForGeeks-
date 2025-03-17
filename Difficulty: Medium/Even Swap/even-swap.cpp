//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
      vector <int> lexicographicallyLargest(vector <int> &a,int n){
            vector <int>ans;
            priority_queue<int>pq;
            int i=0;
            while(i<n){
                int x = a[i]%2;
                while(i<n && x==a[i]%2){
                    pq.push(a[i++]);
                }
                while(!pq.empty()){
                    ans.push_back(pq.top());
                    pq.pop();
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends