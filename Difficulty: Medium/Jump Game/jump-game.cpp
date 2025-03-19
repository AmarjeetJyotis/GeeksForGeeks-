//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
    // Function to check if we can reach the last index from 0th index.
    bool canReach(vector<int> &a) {
       int n=a.size();
        int maxLen=0;
        for(int i=0;i<n;i++){
            if(i>maxLen){
                return  false;
            }
            maxLen=max(maxLen,i+a[i]);
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        int ans = ob.canReach(a);

        if (ans) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends