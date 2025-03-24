//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
   public:
    int dp[11][501]; // Memoization table

    int countSequences(int prev, int len, int n, int m) {
        if (len == n) return 1; // Base case: a valid sequence is formed
        if (dp[len][prev] != -1) return dp[len][prev]; // Return if already computed
        
        int count = 0;
        for (int i = 2 * prev; i <= m; i++) { // Pick valid numbers
            count += countSequences(i, len + 1, n, m);
        }
        
        return dp[len][prev] = count;
    }

    int numberSequence(int n, int m) {
        memset(dp, -1, sizeof(dp)); // Initialize DP table
        int totalCount = 0;
        
        for (int i = 1; i <= m; i++) { // Start sequences with valid numbers
            totalCount += countSequences(i, 1, n, m);
        }
        
        return totalCount;
    }
};


//{ Driver Code Starts.

int main() {
    string s;
    getline(cin, s);
    int t = stoi(s);
    while (t--) {
        getline(cin, s);
        int n = stoi(s);
        getline(cin, s);
        int m = stoi(s);

        Solution ob;
        cout << ob.numberSequence(n, m) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends