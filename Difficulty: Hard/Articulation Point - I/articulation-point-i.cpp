//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function Template for C++

class Solution {
public:
    void dfs(int u, vector<int> adj[], vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& ap, int& time) {
        int children = 0;
        disc[u] = low[u] = ++time;
        
        for (int v : adj[u]) {
            if (disc[v] == -1) {
                children++;
                parent[v] = u;
                dfs(v, adj, disc, low, parent, ap, time);

                low[u] = min(low[u], low[v]);

                if (parent[u] == -1 && children > 1)
                    ap[u] = true;
                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = true;
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> disc(V, -1), low(V, -1), parent(V, -1);
        vector<bool> ap(V, false);
        int time = 0;

        for (int i = 0; i < V; i++) {
            if (disc[i] == -1)
                dfs(i, adj, disc, low, parent, ap, time);
        }

        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (ap[i]) result.push_back(i);
        }

        if (result.empty()) return {-1};
        return result;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends