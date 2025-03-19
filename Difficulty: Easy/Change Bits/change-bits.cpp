//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function Template for C++

class Solution {
  public:
    vector<int> changeBits(int N) {
        // code here
        vector<int> result;
        int numbits = int(log2(N));
        int num = (1<<numbits)-1;
        int res = N|num;
        result.push_back(res-N);
        result.push_back(res);
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends