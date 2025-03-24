//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


 
//User function template for C++

#define ll long long
const int mod = 1e9 + 7;
class Solution {
  public:
    static int f(vector<vector<char>>& v, int i, int j, int p, int q, vector<vector<vector<vector<int>>>>& dp)
{
    // base cases
    if(i >= v.size() || j>=v[0].size() || p<0 || q<0) return 0;
    if(i>p || j>q) return 0;

    if(v[i][j] != v[p][q]) return dp[i][j][p][q] = 0;
    if(i==p && j==q || (abs(i-p) + abs(j-q) <= 1)) return 1;

    if(dp[i][j][p][q]!=-1) return dp[i][j][p][q];

    return dp[i][j][p][q] = ((f(v,i+1,j,p-1,q,dp) + f(v,i+1,j,p,q-1,dp)) % mod + (f(v,i,j+1,p,q-1,dp) + f(v,i,j+1,p-1,q,dp)) % mod) % mod;
}

    int countPalindromicPaths(vector<vector<char>>v){
        // Code here
        int n = v.size(), m = v[0].size();
         vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m,-1))));

        return f(v,0,0,n-1,m-1,dp);
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>matrix(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.countPalindromicPaths(matrix);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends