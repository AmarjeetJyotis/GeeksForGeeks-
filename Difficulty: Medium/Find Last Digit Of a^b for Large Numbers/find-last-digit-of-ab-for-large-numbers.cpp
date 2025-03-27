//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int getLastDigit(string a, string b) {
        // code here
         vector<vector<int>> cycle ={{0},{1},
            {2,4,8,6},
            {3,9,7,1},
            {4,6},
            {5},
            {6},
            {7,9,3,1},
            {8,4,2,6},
            {9,1}
        };
    
        if(b=="0")
            return 1;
        int last = a[a.size()-1] - 48;
        
        vector<int> v = cycle[last];
        int len = v.size();
        
        int exponent=0;
        for(int i=0;i<b.size();i++)
        {
            exponent=(exponent*10+(b[i]-'0'))%len;
        }
        
        if(exponent == 0)
            exponent = len;
        return v[exponent-1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a,b;
        
        cin>>a>>b;

        Solution ob;
        cout << ob.getLastDigit(a,b) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends