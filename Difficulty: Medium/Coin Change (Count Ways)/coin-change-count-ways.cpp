//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    long long dp[1001][1001];
    long long int helper(vector<int> &coins,int n,int sum,int ind){
        if(sum==0)return 1;
        if(ind==n)return 0;
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        
        long long int take=0;
        if(coins[ind]<=sum)take=helper(coins,n,sum-coins[ind],ind);
        long long int notTake=helper(coins,n,sum,ind+1);
        
        return dp[ind][sum]=take+notTake;
    }
  
    long long int count(vector<int> &coins, int sum) {
        // code here.
        memset(dp,-1,sizeof(dp));
        return helper(coins,coins.size(),sum,0);
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends