//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool dfs(int i, vector<vector<int>>& g, int* v) {
        v[i] = 1;
        int j;
        bool ans = false;
        for(int j: g[i]) {
            if(v[j] == 1) {
                return true;
            }
            else {
                if(dfs(j, g, v)) {
                    return true;
                }
            }
        }
        v[i] = 2;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        int v[V] = {0};
        vector<vector<int>> g(V, vector<int>());
        for(auto edge: edges) {
            g[edge[0]].push_back(edge[1]);
        }
        int i;
        for(i = 0; i < V; i++) {
            if(v[i] == 0) {
                if(dfs(i, g, v)) {
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
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends