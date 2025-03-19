//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	long long helper(int idx,int N,int prev,vector<vector<int>> &dp)
	{
	    if(idx==N)
	    {
	        return 1;
	    }
	    if(dp[idx][prev]!=-1)
	    {
	        return dp[idx][prev];
	    }	    
	    long long take=0;
	    long long not_take=helper(idx+1,N,0,dp)%1000000007;
	    if(prev==0)
	    {
	        take=helper(idx+1,N,1,dp)%1000000007;
	    }
	    return dp[idx][prev]=(take+not_take)%1000000007;
	}
	int TotalWays(int N)
	{
	    vector<vector<int>> dp(N,vector<int>(2,-1));
	    long long temp=helper(0,N,0,dp);
	    return (long long)(temp*temp)%1000000007;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends