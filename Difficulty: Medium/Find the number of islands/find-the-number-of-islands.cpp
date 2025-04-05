//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'L') {
                    ++islands;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 'W'; // Mark as visited
                    
                    // Directions for 8 adjacent cells
                    int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                                      {0, -1},          {0, 1},
                                      {1, -1},  {1, 0}, {1, 1}};
                    
                    while (!q.empty()) {
                        auto current = q.front();
                        q.pop();
                        int x = current.first;
                        int y = current.second;
                        
                        for (int k = 0; k < 8; ++k) {
                            int nx = x + dirs[k][0];
                            int ny = y + dirs[k][1];
                            
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 'L') {
                                grid[nx][ny] = 'W';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends