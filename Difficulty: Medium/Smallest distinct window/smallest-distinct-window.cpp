//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findSubString(string& s) {
        unordered_map<char,int>mp,up;
        for(auto &i:s)mp[i]++;
        int low=0,mini=INT_MAX,n=s.size();
        for(int i=0;i<n;i++){
            up[s[i]]++;
            while(low<n && up.size()>=mp.size()){
                mini=min(mini,(i-low)+1);
                up[s[low]]-=1;
                if(up[s[low]]==0)up.erase(s[low]);
                low++;
            }
        }
        return mini;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends