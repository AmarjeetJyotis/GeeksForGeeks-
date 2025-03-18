//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function Template for C++

class Solution{
public:
     void dfs(int i,int s,vector<vector<int>>&adj,vector<int>&vis,int &maxi){
        vis[i]=1;
        maxi=max(maxi,s);
        for(auto it:adj[i]){
            if(!vis[it])dfs(it,s+1,adj,vis,maxi);
        }
        vis[i]=0;
    }
    int partyHouse(int n, vector<vector<int>> &adj){
        int mini=INT_MAX;
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++){
            int maxi=INT_MIN;
            dfs(i,0,adj,vis,maxi);
            mini=min(mini,maxi);
        }
        return mini;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends