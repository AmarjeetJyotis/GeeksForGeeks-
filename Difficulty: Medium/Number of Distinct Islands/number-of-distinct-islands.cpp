//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
private:
void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<int>>& grid,int rb,int cb,vector<pair<int,int>>&p){
    vis[r][c]=1;
    p.push_back({r-rb,c-cb});
    int n=grid.size();
    int m=grid[0].size();
    int delrow[]={-1,0,1,0};
    int delcol[]={0,-1,0,1};
    for(int i=0;i<4;i++){
        int row=r+delrow[i];
        int col=c+delcol[i];
        if(row<n && row>=0 && col<m && col>=0 && vis[row][col]==0 && grid[row][col]==1){
            dfs(row,col,vis,grid,rb,cb,p);
        }
    }
}
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    vector<pair<int,int>> p;
                    dfs(i,j,vis,grid,i,j,p);
                    st.insert(p);
                }
            }
        }
        return st.size();
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends