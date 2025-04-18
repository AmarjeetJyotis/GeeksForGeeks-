//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k+1, 0)));
        queue<vector<int>>q;
        int steps = -1;
        q.push({0,0,k});
        while(!q.empty()){
            int size = q.size();
            steps++;
            while(size--){
                vector<int> curr = q.front();
                q.pop();
                if(curr[0]==n-1 && curr[1]==m-1) return steps;
                if(visited[curr[0]][curr[1]][curr[2]]) continue;
                visited[curr[0]][curr[1]][curr[2]] = true;
                for(int i=0; i<4; i++){
                    int x = curr[0]+dx[i];
                    int y = curr[1]+dy[i];
                    int w = curr[2];
                    if(x>=0&&x<n&&y>=0&&y<m){
                        if(mat[x][y] && w-1>=0 && !visited[x][y][w-1]){
                            q.push({x,y,w-1});
                        }else if(mat[x][y]==0 && !visited[x][y][w]){
                            q.push({x,y,w});
                        }
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends