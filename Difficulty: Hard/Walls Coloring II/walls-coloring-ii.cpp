//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++


//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
    int n = costs.size();
    if (n == 0) return 0;
    int k = costs[0].size();
    if (k == 0 || (k == 1 && n > 1)) return -1;

    // DP table
    vector<vector<int>> dp(n, vector<int>(k, 0));

    // Copy first row
    for (int j = 0; j < k; j++) {
        dp[0][j] = costs[0][j];
    }

    for (int i = 1; i < n; i++) {
        int min1 = INT_MAX, min2 = INT_MAX;

        // Find the two smallest values in the previous row
        for (int j = 0; j < k; j++) {
            if (dp[i - 1][j] < min1) {
                min2 = min1;
                min1 = dp[i - 1][j];
            } else if (dp[i - 1][j] < min2) {
                min2 = dp[i - 1][j];
            }
        }

        // Fill current row
        for (int j = 0; j < k; j++) {
            if (dp[i - 1][j] == min1) {
                dp[i][j] = costs[i][j] + min2; // Avoid same color as previous
            } else {
                dp[i][j] = costs[i][j] + min1;
            }
        }
    }

    // Find the minimum cost in the last row
    int ans = INT_MAX;
    for (int j = 0; j < k; j++) {
        ans = min(ans, dp[n - 1][j]);
    }

    return ans;
}

};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends