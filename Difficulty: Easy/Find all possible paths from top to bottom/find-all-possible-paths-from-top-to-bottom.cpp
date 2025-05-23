//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//User function Template for C++

class Solution
{
public:
vector<vector<int>> v;
void solve(vector<int>ans,int i,int j,int n,int m,vector<vector<int>> &grid){
    
    if(i>=n || j>=m){
        return;
    }
    ans.push_back(grid[i][j]);
    solve(ans,i+1,j,n,m,grid);
    ans.pop_back();
    ans.push_back(grid[i][j]);
    solve(ans,i,j+1,n,m,grid);
    
    if(i==n-1 && j==m-1){
        v.push_back(ans);
    }
}
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        
        v.clear();
        vector<int>ans;
        int i=0;
        int j=0;
        solve(ans,i,j,n,m,grid);
        return v;
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends