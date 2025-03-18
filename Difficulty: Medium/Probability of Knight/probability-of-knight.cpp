//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	int nr[8]={2,2,-2,-2,1,1,-1,-1};
int nc[8]={1,-1,1,-1,2,-2,2,-2};
    double fun(int n ,int k,int row,int col,vector<vector<vector<double>>>&dp)
    {
        if(k<0) return 0;
        if(row<0 || row>=n || col<0 || col>=n) return 0;
        if(k==0) return 1;
        double ans=0;
        if(dp[row][col][k]!=-1) return dp[row][col][k];
        for(int i=0;i<8;i++)
        {
            ans+=fun(n,k-1,row+nr[i],col+nc[i],dp);
        }
        return dp[row][col][k]= ans/8;
    }
	double findProb(int n,int row, int column, int k)
	{
	   vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        return fun(n,k,row,column,dp);
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends