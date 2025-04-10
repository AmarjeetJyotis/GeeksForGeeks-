//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    private:
    int manhattanDistance(const vector<int>& a, const vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
  }
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size();
        vector<int>vis(n,0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        pq.push({0,0});
        int totalCost = 0;
        while(!pq.empty()){
            pair<int, int> top = pq.top();
            pq.pop();

            int cost = top.first;
            int u = top.second;
            if(vis[u]) continue;
            vis[u] = 1;
            totalCost += cost;
            
            for(int v = 0;v<n;v++){
                if(!vis[v]){
                    int dist = manhattanDistance(houses[u],houses[v]);
                    pq.push({dist,v});
                }
            }
        }
        return totalCost;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends