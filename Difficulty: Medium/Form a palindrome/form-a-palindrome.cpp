//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function template for C++

class Solution{
  public:
    int countMin(string str){
        string t = str;
        reverse(t.begin(),t.end());
        int n=str.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = 0 + max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return n - dp[n][m];
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    
cout << "~" << "\n";
}
return 0;
}


// } Driver Code Ends