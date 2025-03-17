//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string removeReverse(string S) {
        map<char, int> m;
        int n = S.length();

        // Count frequency of each character
        for (int i = 0; i < n; i++) {
            m[S[i]]++;
        }

        int i = 0, j = n - 1, count = 0;
        string s1 = "", s2 = "";
        vector<pair<int, char>> v;

        // Two-pointer approach
        while (i <= j) {
            if (count % 2 == 0) { // Left to right
                if (m[S[i]] > 1) {
                    m[S[i]]--;
                    count++;
                } else {
                    s1 += S[i];
                    v.push_back({i, S[i]});
                }
                i++;
            } else { // Right to left
                if (m[S[j]] > 1) {
                    m[S[j]]--;
                    count++;
                } else {
                    s2 += S[j];
                    v.push_back({j, S[j]});
                }
                j--;
            }
        }

        // Sorting the vector based on index
        for (int a = 0; a < v.size() - 1; a++) {
            for (int b = a + 1; b < v.size(); b++) {
                if (v[a].first > v[b].first) {
                    swap(v[a], v[b]);
                }
            }
        }

        string ans = "";
        for (int a = 0; a < v.size(); a++) {
            ans += v[a].second;
        }

        // If last operation was removal from right, reverse the result
        if (count % 2 != 0) {
            for (int a = 0, b = ans.size() - 1; a < b; a++, b--) {
                swap(ans[a], ans[b]);
            }
        }

        return ans;
    }
};





//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends