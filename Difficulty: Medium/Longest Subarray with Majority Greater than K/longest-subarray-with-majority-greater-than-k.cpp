//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> prefix;
        int Sum = 0, maxLen = 0;

        for (int i = 0; i < n; ++i) {
            Sum += (arr[i] > k) ? 1 : -1;
            if (Sum > 0) {
                maxLen = i + 1;
            } else {
                if (prefix.count(Sum - 1)) {
                    maxLen = max(maxLen, i - prefix[Sum - 1]);
                }
            }
            if (!prefix.count(Sum)) {
                prefix[Sum] = i;
            }
        }
        return maxLen;
 }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends