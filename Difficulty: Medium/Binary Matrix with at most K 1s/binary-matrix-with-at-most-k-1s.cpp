//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//User function Template for C++

class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>> M, int R, int C, int K, int Q, int q_i[], int q_j[]) {
       int dp[R][C];
       dp[0][0] = M[0][0];
       for (int i = 1; i < R; i++) {
           dp[i][0] = dp[i-1][0] + M[i][0];
       }
       for (int j = 1; j < C; j++) {
           dp[0][j] = dp[0][j-1] + M[0][j];
       }
       for (int i = 1; i < R; i++) {
           for (int j = 1; j < C; j++) {
               dp[i][j] = M[i][j] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
           }
       }
       vector<int> res;
       for (int q = 0; q < Q; q++) {
           int x = q_i[q], y = q_j[q];
           int min_dist = min({x, y, R - x - 1, C - y - 1});
           int max_size = 0, l = 0, r = min_dist;
           while (l <= r) {
               int mid = (l + r) / 2;
               int minx = x - mid, maxx = x + mid, miny = y - mid, maxy = y + mid;
               int count = dp[maxx][maxy];
               if (minx > 0) {
                   count -= dp[minx-1][maxy];
               }
               if (miny > 0) {
                   count -= dp[maxx][miny-1];
               }
               if (minx > 0 && miny > 0) {
                   count += dp[minx-1][miny-1];
               }
               if (count <= K) {
                   max_size = 2 * mid + 1;
                   l = mid + 1;
               } else {
                   r = mid - 1;
               }
           }
           res.push_back(max_size);
       }
       
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R,C,K,Q,x;
        cin>>R>>C;
        vector<vector<int>> M;
        
        for(int a=0; a<R; a++)
        {
            vector<int> temp;
            for(int b=0; b<C; b++)
            {
                cin>>x;
                temp.push_back(x);
            }
            M.push_back(temp);
        }
        
        cin>>K>>Q;
        
        int q_i[Q], q_j[Q];
        
        for(int i=0; i<Q; i++)
            cin>>q_i[i];
        for(int i=0; i<Q; i++)
            cin>>q_j[i];

        Solution ob;
        vector<int> res = ob.largestSquare(M,R,C,K,Q,q_i,q_j);
        
        for(int i=0; i<Q; i++)
            cout<<res[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends