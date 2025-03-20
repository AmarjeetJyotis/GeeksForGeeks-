//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
     int solve(vector<vector<vector<int>>> &dp, vector<int>& prices, int k, int i, int buy) {
        if (k == 0 || i >= prices.size()) return 0;
        if (dp[i][buy][k] != -1) return dp[i][buy][k];

        int pick = 0, notpick = 0;
        if (buy) { 
           
            pick = prices[i] + solve(dp, prices, k - 1, i + 1, 0);
        } else { 
            pick = -prices[i] + solve(dp, prices, k, i + 1, 1);
        }
        
        notpick = solve(dp, prices, k, i + 1, buy);

        return dp[i][buy][k] = max(pick, notpick);
    }
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int k=2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(dp, prices, k, 0, 0);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends