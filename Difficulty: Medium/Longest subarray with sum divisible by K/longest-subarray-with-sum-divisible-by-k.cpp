//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // Complete the function
        unordered_map<int, int> mp;
        mp[0] = -1; // Initialize remainder 0 at index -1 for handling full prefix sums

        long long prefix_sum = 0;
        int i = 0, j = 0;
        int maxLength = 0;
        
        while (j < arr.size()) {
            prefix_sum += arr[j];  // Expand window by adding arr[j]
            int remainder = prefix_sum % k;
            if (remainder < 0) remainder += k; // Handle negative remainders
            
            if (mp.find(remainder) != mp.end()) {
                maxLength = max(maxLength, j - mp[remainder]);
            } else {
                mp[remainder] = j; // Store the first occurrence of this remainder
            }

            j++; // Expand window
        }

        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.longestSubarrayDivK(arr, d);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends