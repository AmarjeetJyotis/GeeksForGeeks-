//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i = 0;
        int j = n-1;
        int ans = 0;
        while(i < j){
            int height = min(arr[i], arr[j]);
            int width = j - i;
            ans = max(ans, (height * width));
            if(arr[i] < arr[j]){
                i++;
            }
            else{
                j--;
            }
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
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends