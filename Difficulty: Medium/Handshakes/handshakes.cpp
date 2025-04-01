//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution{
public:
    int count(int N){
        vector<int> dp(N / 2 + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= N / 2; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[N / 2];
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends