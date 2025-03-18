//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void getans(string s,int start,int end,vector<int>&ans){
        vector<int>dp(256,0);
        int count=0;
        for(int i=start-1;i<end;i++){
            if(dp[s[i]]==0){
                dp[s[i]]++;
                count++;
            }
        }
        ans.push_back(count);
    }
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    // Code here
	    vector<int>ans;
	    int n=Query.size();
	    for(int i=0;i<n;i++){
	        int start=Query[i][0];
	        int end=Query[i][1];
	    getans(str,start,end,ans);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends