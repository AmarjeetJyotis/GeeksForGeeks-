//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<n; i++) {
            pq.push(arr[i]);
        }
        
        long long n1 = 0, n2 = 0;
        while(!pq.empty()) {
            long long t2;
            long long t1 = pq.top(); pq.pop();
            n1 = n1*10 + t1;
            
            if(!pq.empty()) {
                t2 = pq.top(); pq.pop();
                n2 = n2*10 + t2;
            }
        }
        
        return n1 + n2;
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
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends