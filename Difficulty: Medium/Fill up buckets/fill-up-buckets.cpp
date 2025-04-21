//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++


//User function Template for C++

class Solution{
public:
    long long mod = 1e9+7;
    int totalWays(int n, vector<int>v) {
        sort(v.begin(),v.end());
        long long ans=1;
        for(int i=0;i<n;i++ )
        {
            ans*=v[i]-i;
            ans%=mod;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>capacity(n);
		for(int i = 0; i < n; i++)
			cin >> capacity[i];
		Solution ob;
		int ans = ob.totalWays(n, capacity);
		cout << ans << "\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends