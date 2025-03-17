//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++


// User function Template for C++

class Solution {
  public:
  int find(int par[], int u)
    {
        if (par[u] == -1) {
            return u;
        }
        return find(par, par[u]);
    }
 
    void Union(int par[], int u, int v)
    {
        par[u] = v;
    }
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,
                                  vector<vector<int>> danger, int m) {
                                      int parent[n];
        memset(parent, -1, sizeof(parent));
        vector<string> res;
        for (int i = 0; i < n; i++) {
            int u = find(parent, mix[i][0] - 1);
            int v = find(parent, mix[i][1] - 1);
            int j = 0;
            for (; j < m; j++) {
                int p = find(parent, danger[j][0] - 1);
                int q = find(parent, danger[j][1] - 1);
                if ((u == p && v == q)
                    || (u == q && v == p)) {
                    res.push_back("No");
                    break;
                }
            }
            if (j == m && u == v) {
                res.push_back("Yes");
            }
            if (j == m && u != v) {
                res.push_back("Yes");
                Union(parent, u, v);
            }
        }
        return res;
                                  }
};


//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends