//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    void solve(vector<string>&v , string in , string op)
    {
        if(in.size() == 0)
        {
            v.push_back(op);
            return;
        }
        string op1 = op;
        op1.push_back(' ');
        op1.push_back(in[0]);
        
        string op2 = op;
        op2.push_back(in[0]);
        
        in.erase(in.begin() + 0);
        
        solve(v , in , op1);
        solve(v , in , op2);
    }

    vector<string> permutation(string s) {
        // Code Here
        string in = s;
        string op = "";
        op.push_back(in[0]);
        in.erase(in.begin()+0);
        vector<string> ans;
        solve(ans , in , op);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++) {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends