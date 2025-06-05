class Solution {
  public:
    int dfs(int i, int &s, int &d, vector<vector<int>> &adj, vector<int> &dp){
        if(i == d)
            return 1;
        if(dp[i] != -1)
            return dp[i];
        
        int t = 0;
        
        for(auto z : adj[i]){
            t += dfs(z, s, d, adj, dp);
        }
        
        return dp[i] = t;
    }
  
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int>> adj(V);
        vector<int> dp(V, -1);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
        }
        
        return dfs(src, src, dest, adj, dp);
    }
};
