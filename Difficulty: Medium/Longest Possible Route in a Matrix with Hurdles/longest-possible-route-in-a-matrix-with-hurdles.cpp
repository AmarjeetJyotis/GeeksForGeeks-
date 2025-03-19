//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//User function Template for C++

class Solution {
public:
int maxDist = -1;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // down, up, right, left
    
    void dfs(vector<vector<int>> &matrix, int x, int y, int xd, int yd, int steps) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // If destination is reached, update maximum distance
        if(x==xd && y==yd){
            maxDist=max(maxDist,steps);
            
        }
        int original=matrix[x][y];
        matrix[x][y]=0;
        for(int i=0;i<4;i++){
           int newx=x+directions[i][0];
            int newy=y+directions[i][1];
            
            if(newx>=0 && newy>=0 && newx<n && newy<m && matrix[newx][newy]==1){
                dfs(matrix,newx,newy,xd,yd,steps+1);
            }
        }
        matrix[x][y]=original;
    }
    
    int longestPath(vector<vector<int>> &matrix, int xs, int ys, int xd, int yd) {
        if (matrix[xs][ys] == 0 || matrix[xd][yd] == 0) return -1;
        
        dfs(matrix, xs, ys, xd, yd, 0);
        
        return maxDist;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends