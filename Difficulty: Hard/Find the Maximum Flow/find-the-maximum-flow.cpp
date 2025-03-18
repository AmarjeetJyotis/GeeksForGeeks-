//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    // DFS function to find an augmenting path
    bool dfs(vector<vector<int>> &residualGraph, int u, int t, vector<int> &parent, vector<bool> &visited) {
        visited[u] = true;
        if (u == t) return true; // Found sink

        for (int v = 0; v < residualGraph.size(); v++) {
            if (!visited[v] && residualGraph[u][v] > 0) { // Unvisited with capacity available
                parent[v] = u;
                if (dfs(residualGraph, v, t, parent, visited)) return true;
            }
        }
        return false;
    }

    // Ford-Fulkerson Algorithm
    int findMaxFlow(int N, int M, vector<vector<int>> &Edges) {
        vector<vector<int>> capacity(N + 1, vector<int>(N + 1, 0));

        // Build graph for undirected edges (convert to bidirectional directed edges)
        for (auto &edge : Edges) {
            int u = edge[0];
            int v = edge[1];
            int cap = edge[2];
            capacity[u][v] += cap;
            capacity[v][u] += cap; // Bidirectional for undirected graph
        }

        // Residual graph initialization
        vector<vector<int>> residualGraph = capacity;
        int maxFlow = 0;
        vector<int> parent(N + 1);

        // Augmenting path search using DFS
        while (true) {
            vector<bool> visited(N + 1, false);
            fill(parent.begin(), parent.end(), -1); // Reset parent array

            if (!dfs(residualGraph, 1, N, parent, visited)) break; // No more paths

            // Find the minimum flow in the augmenting path
            int pathFlow = INT_MAX;
            for (int v = N; v != 1; v = parent[v]) {
                int u = parent[v];
                pathFlow = min(pathFlow, residualGraph[u][v]);
            }

            // Update residual capacities in both directions
            for (int v = N; v != 1; v = parent[v]) {
                int u = parent[v];
                residualGraph[u][v] -= pathFlow;
                residualGraph[v][u] += pathFlow; // Backflow capacity adjustment
            }

            maxFlow += pathFlow; // Add path flow to total flow
        }

        return maxFlow;
    }
};;


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int i,j,N,M,u,v,w;
        int res;
        scanf("%d %d",&N,&M);
        vector<vector<int>> Edges; 
        for(i=0;i<M;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
        	Edges.push_back({u,v,w});
    	}
        Solution obj;
        res = obj.findMaxFlow(N, M, Edges);
        cout<<res<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends