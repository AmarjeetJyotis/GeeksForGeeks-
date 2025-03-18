//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++


// User function Template for C++

class Solution {
  public:
    int sum(int a, int b) {
        while (b != 0)
        {
            int carry = (a&b) << 1;
            a = a ^ b;
            b = carry;
        }
        
        return a;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.sum(a, b) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends