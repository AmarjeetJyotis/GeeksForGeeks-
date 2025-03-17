//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++
//User function Template for C++
class Solution{
    public:
    
        int solve(int left,int right,vector<vector<int>>&dp,vector <int> &a) {
            if(left>right)return 0;
            if(left==right)return a[left];
            if(dp[left][right]!=-1)return dp[left][right];
            int i,ans=0;
            for(i=left+1;i<right;i++) {
                ans=max(ans,solve(left,i,dp,a)+ a[left]*a[i]*a[right] + solve(i,right,dp,a));
            }
            return dp[left][right]=ans;
        }
        
        int maxCoins(int N, vector <int> &a)
        {
            // write your code here
            a.insert(a.begin(),1);
            a.push_back(1);
            N+=2;
            vector<vector<int>>dp(N,vector<int>(N,-1));
            solve(0,N-1,dp,a);
            return dp[0][N-1];
        }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends