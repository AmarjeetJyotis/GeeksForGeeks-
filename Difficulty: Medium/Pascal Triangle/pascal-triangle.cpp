//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<int> ans(n, 0);
        ans[0] = 1;
        vector<int> temp(n, 0);
        
        for(int i=2;i<=n;i++){
            temp[0] = 1;
            for(int j=1;j<n;j++){
                temp[j] = ans[j] + ans[j-1];
            }
            for(int x=0;x<n;x++){
                ans[x] = temp[x];
                temp[x] = 0;
            }
        }
        return ans;
    }
};




//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends