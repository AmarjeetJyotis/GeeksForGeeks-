//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    int getMax(vector<int>& nums, int start, int end) {
        int prev = 0, prev2 = 0, curr = 0;

        for (int i = start; i <= end; ++i) {
            // Calculate the maximum stolen value by either:
            // 1. Robbing the current house and adding its value to prev2.
            // 2. Skipping the current house and taking prev.
            curr = max(prev, prev2 + nums[i]);

            // Update prev2 and prev for the next iteration
            prev2 = prev;
            prev = curr;
        }

        return curr;
    }
  public:
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();

        // Since the houses are in a circle, consider two scenarios:
        // 1. Exclude the last house.
        // 2. Exclude the first house.
        int val1 = getMax(arr, 0, n - 2);
        int val2 = getMax(arr, 1, n - 1);

        // Return the maximum stolen value from both scenarios
        return max(val1, val2);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends