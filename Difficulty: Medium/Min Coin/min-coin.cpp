//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	int MinCoin(vector<int>nums, int amount){
	    
        int m=nums.size(), n=amount;
        
        vector<vector<int>> dp(m,vector<int>(n+1));
        
        for(int s=0;s<=n;s++)
            dp[0][s] = s%nums[0]==0 ? s/nums[0] : (int)(1e9);
        
        for(int i=1;i<m;i++)
        {
            for(int s=0;s<=n;s++)
            {
                int not_take = 0 + dp[i-1][s];
                
                int take=INT_MAX;
                if(nums[i]<=s)
                    take = 1 + dp[i][s-nums[i]];
                    
                dp[i][s] = min(take,not_take);
            }
        }
        
        return dp[m-1][n]<(int)(1e9) ? dp[m-1][n]:-1;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends