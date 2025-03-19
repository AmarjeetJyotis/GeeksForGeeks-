//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int m = grid.size() ;
        int n = grid[0].size() ;
        
        queue<pair<int, int>> q ;
        vector<vector<int>> vis(m, vector<int>(n, 0)) ;
        int delr[4] = {-1, 0, 1, 0} ;
        int delc[4] = {0, 1, 0, -1} ;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    vis[i][j] = 1 ;
                    q.push({i, j}) ;
                    break ;
                }
            }
        }
        
        while(!q.empty()){
            auto it = q.front() ;
            int row = it.first ;
            int col = it.second; 
            q.pop() ;
            
            if(grid[row][col] == 2){
                return 1 ;
            }
            
            for(int i=0; i<4; i++){
                int nrow = row + delr[i] ;
                int ncol = col + delc[i] ;
                
                if(nrow >=0 && nrow < m && ncol >=0 && ncol < n && vis[nrow][ncol] == 0 && 
                   grid[nrow][ncol] != 0){
                       vis[nrow][ncol] = 1 ;
                       q.push({nrow, ncol}) ;
                   }
                
            }
        }
        return 0 ;
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
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends