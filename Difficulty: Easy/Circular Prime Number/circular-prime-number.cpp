//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> isCircularPrime(int n) {
        int limit = max(n, 100000);
        vector<bool> prime(limit, true);
        prime[0] = prime[1] = false;
    
        for (int p = 2; p * p < limit; p++) {
            if (prime[p]) {
                for (int i = p * p; i < limit; i += p)
                    prime[i] = false;
            }
        }
    
        vector<int> ans;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                string num = to_string(i);
                int len = num.length();
                bool isCircular = true;
    
                for (int j = 0; j < len; j++) {
                    rotate(num.begin(), num.begin() + 1, num.end());
                    int rotatedNum = stoi(num);
                    if (!prime[rotatedNum]) {
                        isCircular = false;
                        break;
                    }
                }
                if (isCircular) {
                    ans.push_back(i);
                }
            }
        }
    
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int> ans = ob.isCircularPrime(n);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends