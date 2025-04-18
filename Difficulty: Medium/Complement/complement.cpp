//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends


class Solution{
public:
    vector<int> findRange(string str, int n) {
        // code here
        int max_sum = -1;
        int current_sum = 0;
        int start = 0, best_l = -1, best_r = -1;

        for(int i = 0; i < n; i++) {
            int val = (str[i] == '0') ? 1 : -1;
            current_sum += val;

            if (current_sum < 0) {
                current_sum = 0;
                start = i + 1;
            } else if (current_sum > max_sum) {
                max_sum = current_sum;
                best_l = start;
                best_r = i;
            }
        }

        if (best_l == -1) return {-1}; 
        return {best_l + 1, best_r + 1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends