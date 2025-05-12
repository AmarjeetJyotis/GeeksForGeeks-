//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
    int find(int node, int start, int end, int a, int b, vector<int> &tree) {
        if(start == end) {
            tree[node] = max(tree[node], a) + b - a;
            return start;
        }
        
        int ans = -1, mid = (start + end) / 2;
        
        if(tree[2 * node + 1] <= a) ans = find(2 * node + 1, start, mid, a, b, tree);
        else if(tree[2 * node + 2] <= a) ans = find(2 * node + 2, mid + 1, end, a, b, tree);
        else {
            if(tree[node * 2 + 1] <= tree[node * 2 + 2]) ans = find(2 * node + 1, start, mid, a, b, tree);
            else ans = find(2 * node + 2, mid + 1, end, a, b, tree);
        }
        
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        
        return ans;
        
    }
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
        int m = meetings.size(), maxi = -1;
        
        vector<int> freq(n, 0), tree(4 * n, 0);
        
        sort(meetings.begin(), meetings.end());
        
        for(int i = 0; i < m; i++) {
            
            int idx = find(0, 0, n - 1, meetings[i][0], meetings[i][1], tree);
            // cout << idx << endl;
            freq[idx]++;
            
        }
        
        for(int i = 0; i < n; i++) maxi = max(maxi, freq[i]);
        
        for(int i = 0; i < n; i++) if(freq[i] == maxi) return i;
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends