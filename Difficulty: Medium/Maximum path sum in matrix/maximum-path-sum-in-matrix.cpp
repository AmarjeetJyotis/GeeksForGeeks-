//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
  int path(int i, int j, int m,vector<vector<int>> &mat, vector<vector<int>> &dp){
      if(j<0 || j>=m){
          return INT_MIN;
      }
      
      if(i==0){
          return mat[i][j];
      }
      
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      
      int up = path(i-1, j, m, mat, dp);
      int dia1 = path(i-1, j+1, m, mat, dp);
      int dia2 = path(i-1, j-1, m, mat, dp);
      return dp[i][j] = mat[i][j] + max(up, max(dia1,dia2));
  }
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int maxi = INT_MIN;
        int n = mat.size();
        int m = mat[0].size();
        // vector<vector<int>> dp(n, vector<int>(m,-1));
        // for(int j = 0; j<m; j++){
        //     maxi = max(maxi, path(n-1, j, m, mat, dp));
        // }
        // return maxi;
        vector<int> prev(m);
        for(int j = 0; j<m; j++)
        {
            prev[j] = mat[0][j];
        }
        
        for(int i = 1; i<n ; i++)
        {
            vector<int> curr(m);
            for(int j = 0; j<m; j++)
            {
                int up = prev[j];
                int dia1 = (j - 1 >= 0) ? prev[j - 1] : INT_MIN;
                int dia2 = (j + 1 < m) ? prev[j + 1] : INT_MIN;
                curr[j] = mat[i][j] + max(up, max(dia1,dia2));
            }
            prev = curr;
        }
        
        for(int i = 0; i<m ;i++)
        {
            maxi = max(maxi, prev[i]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout << ob.maximumPath(mat) << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends