//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) { vector<int> dis(V, INT_MAX);
        dis[src] = 0;
        
        vector<vector<pair<int, int>>> adj(V);
        for(auto z : edges){
            adj[z[0]].push_back({z[1], z[2]});
            adj[z[1]].push_back({z[0], z[2]});
        }
        
        
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            
            for(auto x : adj[ele.first]){
                int w = x.second;
                if((dis[ele.first]+ w)< dis[x.first]){
                    dis[x.first] = dis[ele.first]+ w;
                    q.push({x.first, dis[x.first]});
                }
            }
            
        }
        
        return dis;
        
        // Code here
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends