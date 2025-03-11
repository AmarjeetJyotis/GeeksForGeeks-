//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int left = 0, current_sum = 0;
        
        for (int right = 0; right < arr.size(); right++) {
            current_sum += arr[right];

            // Shrink window if current_sum exceeds target
            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }

            // Check if we found the target sum
            if (current_sum == target) {
                return {left + 1, right + 1};  // Convert to 1-based index
            }
        }
        
        return {-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends