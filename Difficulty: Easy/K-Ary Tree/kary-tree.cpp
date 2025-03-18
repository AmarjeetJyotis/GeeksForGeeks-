//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function Template for C++



class Solution {
  public:
    long long modExp(long long k, long long m, long long mod) {
        long long result = 1;
        while (m > 0) {
            if (m % 2 == 1) {
                result = (result * k) % mod; // Apply mod after multiplication
            }
            k = (k * k) % mod; // Always take mod after squaring
            m /= 2;
        }
        return result;
    }

    long long karyTree(int k, int m) {
        int MOD = 1e9 + 7;
        return modExp(k, m, MOD);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends