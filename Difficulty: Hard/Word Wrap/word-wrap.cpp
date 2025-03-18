//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
  
    int solve(int n,int index,int rem,vector<vector<int>> &dp,vector<int> &arr,int k){
        if(index==n){
            return 0;
        }
        if(dp[index][rem+1]!=-1){
            return dp[index][rem+1];
        }
        
        int choice1=(rem+1)*(rem+1)+solve(n,index+1,k-arr[index]-1,dp,arr,k);
        if(arr[index]>rem){
            return dp[index][rem+1]=choice1;
        }
        int choice2=0+solve(n,index+1,rem-arr[index]-1,dp,arr,k);
        return dp[index][rem+1]=min(choice1,choice2);
    }
    int solveWordWrap(vector<int> arr, int k) {
        int n=arr.size();
        
        vector<vector<int>> dp(n,vector<int>(k+2,-1));
        return solve(n,0,k,dp,arr,k);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        string str1;
        getline(cin, str1);

        stringstream ss1(str1);
        int k;
        int num1;
        while (ss1 >> num1) {
            k = num1;
        }
        Solution obj;
        cout << obj.solveWordWrap(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends