//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos,int n) {
        // Code here
        // knight possilbe steps
        int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
        int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
        
        set<pair<int,int>> seen;
        
        queue<vector<int>> position;
        
        position.push({knightPos[0], knightPos[1], 0});
        
        while(!position.empty()){
            auto it = position.front();
            position.pop();
            
            int x = it[0];
            int y = it[1];
            int steps = it[2];
            
            // reached target 
            if(x == targetPos[0] and y == targetPos[1])
            {
                return steps;
            }
            
            for(int i = 0; i < 8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 1 and nx <= n and ny >= 1 and ny <= n and !seen.count({nx,ny})){
                    seen.insert({nx, ny});
                    position.push({nx, ny, steps + 1});
                }
            }
        }
        
        return -1;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        vector<int> knightPos(2);
        vector<int> targetPos(2);
        int N;
        cin >> N;
        cin >> knightPos[0] >> knightPos[1];
        cin >> targetPos[0] >> targetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(knightPos, targetPos, N);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends