//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends






class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
int minimumCostPath(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();
    
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[0][0] = grid[0][0];
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({dist[0][0], {0, 0}});
    
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        int currentDist = current.first;
        int i = current.second.first;
        int j = current.second.second;
        
        if (i == m - 1 && j == n - 1) {
            return currentDist;
        }
        
        if (currentDist > dist[i][j]) {
            continue;
        }
        
        for (auto& dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            
            if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                int newDist = currentDist + grid[ni][nj];
                if (newDist < dist[ni][nj]) {
                    dist[ni][nj] = newDist;
                    pq.push({newDist, {ni, nj}});
                }
            }
        }
    }
    
    return dist[m - 1][n - 1];
}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends