//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int closestToZero(int arr[], int n) {
        sort(arr, arr + n);  
        int l = 0, r = n - 1;
        int closest_sum = INT_MAX;
        int maxsum = INT_MIN;

        while (l < r) {
            int sum = arr[l] + arr[r];

            if (abs(sum) < abs(closest_sum)) {
                closest_sum = sum;
                maxsum = sum;
            } 
            else if (abs(sum) == abs(closest_sum)) {
                maxsum = max(maxsum, sum);
            }

            if (sum < 0) {
                l++;  
            } else {
                r--;  
            }
        }
        return maxsum;
    }
};

//{ Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends