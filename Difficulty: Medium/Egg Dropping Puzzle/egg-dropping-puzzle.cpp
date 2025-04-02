//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:

    
    int eggDrop(int n, int k) {
        vector<int> dp(n+1,0);
        int count =0 ;
        while(dp[n] < k){
            count++;
            for(int i=n;i>0;i--){
                dp[i] += 1 + dp[i-1];
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends