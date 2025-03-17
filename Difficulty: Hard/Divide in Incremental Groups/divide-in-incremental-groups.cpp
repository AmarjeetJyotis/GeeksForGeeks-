//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
    int dp[101][101][101];
    int countWaystoDivide(int N, int K) {
        // Code here
        memset(dp, -1, sizeof(dp));
        return recurse(0, 1, N, K);
    }

private:
    int recurse(int pos, int prev, int left, int K) {
        if(pos == K) {
            if(left == 0) return 1;
            return 0;
        }
        
        if(left == 0) return 0;
        
        if(dp[pos][prev][left] != -1) return dp[pos][prev][left];
        
        int ans = 0;
        
        for(int i = prev; i <= left; i++) {
            ans += recurse(pos + 1, i, left - i, K);
        }
        return dp[pos][prev][left] = ans;
    }
};
/*

N total sum, K elements.

dp[i][j] = i total sum, j elements.

examples

8, 4

 1 1 1 5
 1 1 2 4
 1 1 3 3
 1 2 2 3
 2 2 2 2

*/


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends