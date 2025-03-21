//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++
//  User function template for C++

class SegmentTree {
public:
    vector<int> seg;
    int N;

    SegmentTree(int n) {
        N = n;
        seg.assign(4 * n, 0);
    }

    void update(int node, int low, int high, int idx, int val) {
        if (low == high) {
            seg[node] += val;
            return;
        }

        int mid = (low + high) / 2;

        if (idx <= mid) {
            update(2 * node + 1, low, mid, idx, val);
        } else {
            update(2 * node + 2, mid + 1, high, idx, val);
        }

        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    int query(int node, int low, int high, int l, int r) {
        if (r < low || high < l) return 0; 
        if (l <= low && high <= r) return seg[node]; 

        int mid = (low + high) / 2;
        return query(2 * node + 1, low, mid, l, r) + 
               query(2 * node + 2, mid + 1, high, l, r);
    }

    void update(int idx, int val) {
        update(0, 0, N - 1, idx, val);
    }

    int query(int l, int r) {
        if (l > r) return 0; 
        return query(0, 0, N - 1, l, r);
    }
};

class Solution {
public:
    vector<int> constructLowerArray(vector<int> &arr) {
        set<int, greater<int>> st(arr.begin(), arr.end());
        unordered_map<int, int> indices;
        int n = arr.size();
        int k = 0;
        for (int i : st) {
            indices[i] = k++;
        }

        vector<int> res(n);
        SegmentTree segt(k);

        for (int j = n - 1; j >= 0; j--) {
            int idx = indices[arr[j]];
            res[j] = segt.query(idx + 1, k - 1); 
            segt.update(idx, 1);
        }

        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends