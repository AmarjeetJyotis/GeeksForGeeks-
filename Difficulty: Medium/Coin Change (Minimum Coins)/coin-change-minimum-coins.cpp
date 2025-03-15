//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int solve(vector<int>& coins,int rem,int i,vector<vector<int>>& dp) {
	    if (i==0) {
	        if (rem%coins[0]==0) {
	            return rem/coins[0];
	        }
	        return 1e9;
	    }
	    if (dp[i][rem]!=-1) return dp[i][rem];
	    int no=solve(coins,rem,i-1,dp);
	    int take=1e9;
	    if(coins[i]<=rem) {
	        take=1+solve(coins,rem-coins[i],i,dp);
	    }
	    return dp[i][rem]= min(take,no);
	}
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n=coins.size();
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
	    int ans=solve(coins,sum,n-1,dp);
	    return ans>=1e9 ? -1:  ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends