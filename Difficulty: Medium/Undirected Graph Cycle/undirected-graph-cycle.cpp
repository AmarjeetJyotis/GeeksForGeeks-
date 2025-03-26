//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool solve(vector<vector<int>> &adj,vector<int> &parent,
    vector<int> &vis,int node){
        parent[node]=-1;
        vis[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto it:adj[front]){
                if(!vis[it]){
                    vis[it]=1;
                    parent[it]=front;
                    q.push(it);
                }
                else if(vis[it] && parent[front]!=it){
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        vector<int> vis(adj.size(),0);
        vector<int> parent(adj.size(),-1);
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                bool ans=solve(adj,parent,vis,i);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends