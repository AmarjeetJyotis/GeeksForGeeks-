//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function Template for C++

class Solution{
    public:
     int solve(int h, int m, int path, unordered_map<string, int>& dp) {
        // Base Case: Game ends if health or mana drops to zero or below
        if (h <= 0 || m <= 0) {
            return 0;
        }

        string key = to_string(h) + "," + to_string(m) + "," + to_string(path);
        
        // Check memoization table
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        if (path == 0) {
            dp[key] = 1 + max(solve(h - 5, m - 10, 1, dp), solve(h + 3, m + 2, 2, dp));
        }
        else if (path == 1) {
            dp[key] = 1 + max(solve(h - 20, m + 5, 0, dp), solve(h + 3, m + 2, 2, dp));
        }
        else if (path == 2) {
            dp[key] = 1 + max(solve(h - 20, m + 5, 0, dp), solve(h - 5, m - 10, 1, dp));
        }

        return dp[key];
    }

    int maxLevel(int h, int m) {
        // Use unordered_map instead of large dp table to prevent memory overflow
        unordered_map<string, int> dp;
        
        // Check all possible starting paths and take the maximum
        return max({solve(h, m, 0, dp), solve(h, m, 1, dp), solve(h, m, 2, dp)}) - 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    Solution a;
    while(t--)
    {
        int h,m;
        cin>>h>>m;
        cout<<a.maxLevel(h,m)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends