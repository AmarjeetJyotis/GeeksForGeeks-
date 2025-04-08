//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    void solve(int V,vector<vector<int>>&mat,vector<int>&vis,int i){
        
        vis[i]=false;
        
        for(auto a:mat[i]){
            if(vis[a]){
                solve(V,mat,vis,a);
            }
        }
        
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        
        vector<vector<int>>mat1(V,vector<int>());
        vector<vector<int>>mat2(V,vector<int>());
        
        for(auto i:edges){
             mat1[i[0]].push_back(i[1]);
             mat1[i[1]].push_back(i[0]);
        }
        
        for(auto i:edges){
            if((i[0]==c && i[1]==d) || (i[0]==d && i[1]==c)){
                
            }
            else{
                mat2[i[0]].push_back(i[1]);
                mat2[i[1]].push_back(i[0]);
            }
        }
        
        vector<int>v(V,true);
        int count1=0;
         for(int i=0;i<V;i++){
            
            if(v[i]) {
                count1++;
                solve(V,mat1,v,i);
            }
            
        }
        
        
        
        vector<int>vis(V,true);
        int count2 = 0;
        for(int i=0;i<V;i++){
            
            if(vis[i]) {
                count2++;
                solve(V,mat2,vis,i);
            }
            
        }
        
        
        return (count2-count1)>0?true:false;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends