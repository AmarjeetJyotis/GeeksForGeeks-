//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



// User function Template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int ans = arr[n-1]-arr[0];
        for(int i = 1; i<n ;i++)
        {
            int height1 = min( arr[i]-k , arr[0]+k);
            int height2 = max(arr[i-1]+k , arr[n-1]-k);
            ans = min(ans, height2-height1);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.getMinDiff(arr, k) << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends