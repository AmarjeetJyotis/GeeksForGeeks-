//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool canPair(vector<int> &arr, int k) {
        // Code here.
        int n = arr.size();
        if(n%2 == 1) {
            return false;
        }
        unordered_set<int>st;
        for(int i = 0; i < n; i++) {
            int r1 = arr[i]%k;
            int r2 = k - r1;
            if(st.find(r2) != st.end()) {
                st.erase(r2);
            } else if( r1 == 0 && st.find(0)!= st.end()) {
                st.erase(0);
            } else {
                st.insert(r1);
            }
        }
        return st.size() == 0;
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
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        bool ans = obj.canPair(arr, k);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends