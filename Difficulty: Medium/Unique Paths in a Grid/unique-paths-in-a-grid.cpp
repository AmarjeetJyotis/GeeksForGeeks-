class Solution {
  public:
    int n, m;
    int solve(int i, int j, vector <vector <int>>& grid, vector <vector <int>>& dp){
        if(i >= n || j >= m || grid[i][j] == 1) return 0;
        if(i == n-1 && j == m-1) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int total = solve(i+1, j, grid, dp) + solve(i, j+1, grid, dp);
        
        return dp[i][j] = total;
    }
    int uniquePaths(vector<vector<int>> &grid) {
        n = grid.size();
        m = grid[0].size();
        vector <vector <int>> dp(n, vector <int> (m, -1));
        
        if(grid[0][0] == 1) return 0;
        return solve(0, 0, grid, dp);
    }

};