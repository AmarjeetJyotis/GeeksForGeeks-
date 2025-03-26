//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
  vector<vector<int>> dp;
    int help(int i,int &p,int k,vector<int>& nums){
        if(i==nums.size()){
            if(p<=k)
            return 1;
            else
            return 0;
        }
        if(p>k)return 0;
        if(dp[i][p]!=-1)return dp[i][p];
        p*=nums[i];
        int a=help(i+1,p,k,nums);
        p/=nums[i];
        int b=help(i+1,p,k,nums);
        return dp[i][p]=a+b;
    }
    int numOfSubsets(vector<int>& arr, int k) {
        // code here
        int p=1;
        dp.resize(arr.size()+1,vector<int>(k+1,-1));
        return help(0,p,k,arr)-1;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.numOfSubsets(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends