//{ Driver Code Starts
// Initial Template for C++

// Initial Template for C++
// Back-end complete function Template for C++
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

// User function Template for C++

class Solution {
  public:
  long lcmTriplets(long long n) {

        // code here

        if(n<=2) return n;

        if((n&1)==1) return (n-2)*(n-1)*(n);

        if((n%3)==0) return (n-2)*(n-1)*(n-3);

        return (n-3)*(n-1)*(n);

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.lcmTriplets(N) << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends