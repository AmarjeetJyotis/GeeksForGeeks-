//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(vector<vector<int>> &mat) {
        // code here
        
        /*
            approach 1
            1. Maintain a left and right boundary
            2. Use temp[] array to keep track of the sum of all elements in a col, compressed to 1 value
            3. Iterate from left to right and calculate the max_sum
            4. left will iterate from 0 to n-1, and update the max_sum for each left.
            
            approach 2
            5. Can try subtracting the from the calculated sum.
        */
        
        int m = mat.size();
        int n = mat[0].size();
        
        int left, right;
        int max_so_far = INT_MIN;
        int max_sum = INT_MIN;
        
        for (left = 0; left < n; left++)
        {
            vector<int> temp(m, 0);
            
            for (right = left; right < n; right++)      // 0, 1, 2, 3
            {
                // iterate through all rows of col right
                for (int i = 0; i < m; i++)
                {
                    temp[i] += mat[i][right];
                }
                
                // Kaden's algo for max subarray sum
                int sum_ending_here = 0;
                for (int i = 0; i < temp.size(); i++)
                {
                    sum_ending_here += temp[i];
                    max_so_far = max(max_so_far, max(temp[i], sum_ending_here));

                    if (sum_ending_here < 0) {
                        sum_ending_here = 0; // Reset if sum becomes negative
                    } 
                }
                max_sum = max(max_sum, max_so_far);
            }
        }
        
        return max_sum;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(v) << "\n";
    }
}
// } Driver Code Ends