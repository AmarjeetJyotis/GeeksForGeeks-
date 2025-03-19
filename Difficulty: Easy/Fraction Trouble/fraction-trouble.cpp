//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<int> numAndDen(int n, int d) {
        int best_num = 0, best_den = 1;
        double max_frac = 0.0;

        for (int q = 1; q <= 10000; ++q) {
            int p = (n * q - 1) / d;
            if (p <= q) {
                if (__gcd(p, q) == 1) {
                    double current = static_cast<double>(p) / q;
                    if (current > max_frac) {
                        max_frac = current;
                        best_num = p;
                        best_den = q;
                    }
                }
            }
        }

        return {best_num, best_den};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends