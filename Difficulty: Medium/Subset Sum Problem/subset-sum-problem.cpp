//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool solve(int i,vector<int>&arr,int sum,vector<vector<int>>&dp){
        if(sum==0){
            return true;
        }
        if(sum<0)return false;
        if(i==arr.size()){
            return false;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool take=solve(i+1,arr,sum-arr[i],dp);
        bool nottake=solve(i+1,arr,sum,dp);
        return dp[i][sum]=take||nottake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n= arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(0,arr,sum,dp);
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends