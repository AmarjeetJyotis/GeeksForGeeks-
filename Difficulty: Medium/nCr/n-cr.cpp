//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
//   unordered_map<int,unordered_map<int,int>>m;
    int nCr(int n, int r) {
        // code here
        // if(r>n) return 0;
        // if(r==0) return 1;
        // if(m.count(n) and m[n].count(r)) return m[n][r];
        // return m[n][r]=nCr(n-1,r-1)+nCr(n-1,r);
         unordered_map<int,unordered_map<int,int>>m;
         for(int i=0;i<n+1;i++){
             for(int j=0;j<r+1;j++){
                 if(r>n) {m[i][j]=0;continue;}
                 if(j==0){m[i][j]=1;continue;}
                 m[i][j]=m[i-1][j-1]+m[i-1][j];
             }
         }
         return m[n][r];
    }
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends