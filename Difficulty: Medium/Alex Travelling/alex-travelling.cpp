//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        int e = flights.size();
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i =0;i<e;i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n+1,INT_MAX);
        vector<int> explored(n+1,-1);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q; // wt, node
        q.push({0,k});
        dist[k]=0;
        while(!q.empty()){
            int node = q.top().second;
            q.pop();
            // if(explored[node]){
            //     continue;
            // }
            // explored[node]=1;
            
            for(int j =0;j<adj[node].size();j++){
                int neigh = adj[node][j].first;
                int wt = adj[node][j].second;
                
                if(dist[node]+wt<dist[neigh]){
                    dist[neigh]=dist[node]+wt;
                    q.push({dist[neigh],neigh});
                }
            }
        }
        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;  
            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends