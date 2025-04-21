//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    long long jumpingNums(long long n) {
        if (n <= 9) return n; // If n is a single-digit number, return n itself.

        queue<long long> q;

        // Initialize the queue with all single-digit numbers (Jumping Numbers)
        for (int i = 1; i <= 9; i++) {
            q.push(i);
        }

        long long result = 0;

        while (!q.empty()) {
            long long num = q.front();
            q.pop();

            // Update the largest Jumping Number found so far
            if (num <= n) {
                result = max(result, num);
            }

            // Stop further processing if num exceeds n
            if (num > n) {
                continue;
            }

            // Get the last digit of the current Jumping Number
            int last_digit = num % 10;

            // Generate the next Jumping Numbers by appending valid digits
            if (last_digit > 0) { // Append (last_digit - 1) if valid
                q.push(num * 10 + (last_digit - 1));
            }
            if (last_digit < 9) { // Append (last_digit + 1) if valid
                q.push(num * 10 + (last_digit + 1));
            }
        }

        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        cout << ob.jumpingNums(n) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends