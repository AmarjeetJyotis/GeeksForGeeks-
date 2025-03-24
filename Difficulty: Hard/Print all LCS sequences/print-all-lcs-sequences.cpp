//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    set<string> getAllLCS(string &s, string &t, vector<vector<int>> &dp, int i, int j, map<pair<int, int>, set<string>> &memo) {
    if (i == 0 || j == 0)
        return {""};

    if (memo.find({i, j}) != memo.end())
        return memo[{i, j}];

    set<string> result;

    if (s[i - 1] == t[j - 1]) {
        set<string> temp = getAllLCS(s, t, dp, i - 1, j - 1, memo);
        for (string str : temp) {
            result.insert(str + s[i - 1]);
        }
    } else {
        if (dp[i - 1][j] >= dp[i][j - 1]) {
            set<string> top = getAllLCS(s, t, dp, i - 1, j, memo);
            result.insert(top.begin(), top.end());
        }
        if (dp[i][j - 1] >= dp[i - 1][j]) {
            set<string> left = getAllLCS(s, t, dp, i, j - 1, memo);
            result.insert(left.begin(), left.end());
        }
    }

    return memo[{i, j}] = result;
}
  public:
   vector<string> all_longest_common_subsequences(string s, string t) {
        
        int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the LCS length table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Backtrack to find one LCS
     map<pair<int, int>, set<string>> memo;
    set<string> allLCS = getAllLCS(s, t, dp, m, n, memo);

    // Convert to vector and sort for lexicographical order
    vector<string> result(allLCS.begin(), allLCS.end());
    sort(result.begin(), result.end());

    // Print results
    return result;
   }
};



//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends