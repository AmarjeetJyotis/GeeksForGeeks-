//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
   vector<int> mintime(vector<vector<int>>& mat) 
   {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> burn(n * m, -1); 
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (mat[i][j] == 2) 
                {
                    q.push({0, {i, j}});
                    burn[i * m + j] = 0;
                } 
                else if (mat[i][j] == 0) 
                {
                    burn[i * m + j] = 0; 
                }
            }
        }  
        
        while (!q.empty()) 
        {
            auto current = q.front();
            int time = current.first;
            int row = current.second.first;
            int col = current.second.second;
            q.pop();
            
    
            if (row - 1 >= 0 && mat[row - 1][col] == 1 && burn[(row - 1) * m + col] == -1)
            {
                burn[(row - 1) * m + col] = time + 1;
                q.push({time + 1, {row - 1, col}});
            }
            
            if (row + 1 < n && mat[row + 1][col] == 1 && burn[(row + 1) * m + col] == -1) 
            {
                burn[(row + 1) * m + col] = time + 1;
                q.push({time + 1, {row + 1, col}});
            }

            if (col - 1 >= 0 && mat[row][col - 1] == 1 && burn[row * m + (col - 1)] == -1) 
            {
                burn[row * m + (col - 1)] = time + 1;
                q.push({time + 1, {row, col - 1}});
            }

            if (col + 1 < m && mat[row][col + 1] == 1 && burn[row * m + (col + 1)] == -1) 
            {
                burn[row * m + (col + 1)] = time + 1;
                q.push({time + 1, {row, col + 1}});
            }
        }
        
        return burn;
    }
  
    int orangesRotting(vector<vector<int>>& mat) 
    {   
        if (mat.empty() || mat[0].empty()) 
        return 0;
        
        int n = mat.size();
        int m = mat[0].size();
        
        
        if (n == 1 && m == 1) 
        {
            if(mat[0][0]==2 || mat[0][0]==0)
            return 0;
            else
            return -1;
        }
        
        vector<int> burn = mintime(mat);
        int maxTime = 0;
        
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                int index = i * m + j;
                if (mat[i][j] == 1) 
                {
                    if (burn[index] == -1) 
                    {
                        return -1; 
                    }
                    maxTime = max(maxTime, burn[index]);
                }
            }
        }
        
        return maxTime;
    }
    
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends