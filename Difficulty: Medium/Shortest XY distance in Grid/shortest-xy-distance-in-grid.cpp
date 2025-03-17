//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> a, int n, int m) {
        int i,j,k;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if (a[i][j] == 'X') {
                    q.push({i,j});
                }
            }
        }
        pair<int,int> v[] = {{0,1}, {1,0}, {0, -1}, {-1,0}};
        int dist = 0;
        while(!q.empty()) {
            j = q.size();
            while(j--) {
                pair<int,int> p = q.front();
                q.pop();
                if(vis[p.first][p.second])
                    continue;
                // cout<<p.first<<" "<<p.second<<endl;

                vis[p.first][p.second] = true;
                if(a[p.first][p.second] == 'Y') {
                    return dist;
                }
                for(i=0;i<4;i++) {
                    int x = v[i].first + p.first;
                    int y = v[i].second + p.second;
                    // if ()
                    // cout<<x<<"#"<<y<<"$"<<vis[x][y]<<endl;
                    if(x>=0 && x<n && y>=0 && y<m && !vis[x][y]) {
                        // cout<<"*"<<endl;
                        q.push({x,y});
                    }
                }
            }
            dist++;
        }
        return dist;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends