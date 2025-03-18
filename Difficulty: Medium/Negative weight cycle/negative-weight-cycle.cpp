//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>dist(n,INT_MAX) ; 
	   // dist[0] = 0  ; 
	    for(int src = 0 ; src < n ; src ++){
	        dist[src] = 0 ; 
    	   for(auto edge : edges){
    	        int u = edge[0] ; 
    	        int v = edge[1] ; 
    	        int w = edge[2] ; 
    	       // if(dist[u] == INT_MAX) continue ; 
    	        if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
    	            dist[v] = dist[u] + w  ; 
    	        }
	        }
    	    for(auto &edge : edges){
    	        int u = edge[0] ; 
    	        int v = edge[1] ; 
    	        int w = edge[2] ; 
    	       // if(dist[u] == INT_MAX) continue ; 
    	        if(dist[u] != INT_MAX && dist[u] + w < dist[v] ) return true ; //negative cycle detected ; 
    	    }
	    }
	    
	    return false ; 
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends