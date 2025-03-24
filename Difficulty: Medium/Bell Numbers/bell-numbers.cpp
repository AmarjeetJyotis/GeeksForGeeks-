//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int stirling(int n, int k) {
  
    // Base cases
    if (n == 0 && k == 0) return 1;
    if (k == 0 || n == 0) return 0;
    if (n == k) return 1;
    if (k == 1) return 1;


    // Recursive formula
    return k * stirling(n - 1, k) + stirling(n - 1, k - 1);
}

// Function to calculate the total number of 
// ways to partition a set of `n` elements
int bellNumber(int n) {
  
    int result = 0;

    // Sum up Stirling numbers S(n, k) for all
      // k from 1 to n
    for (int k = 1; k <= n; ++k) {
        result += stirling(n, k);
    }
    return result;
}
};



//{ Driver Code Starts.

int main() {
    Solution obj;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << obj.bellNumber(n) << "\n";
    }
    return 0;
}
// } Driver Code Ends