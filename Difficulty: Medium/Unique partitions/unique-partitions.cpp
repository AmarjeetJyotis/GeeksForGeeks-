//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    void partition(int i,vector<int>&temp,vector<vector<int>>&ans,int n){
        // base case
        if(n<0) return;
        if(n==0){
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            reverse(temp.begin(),temp.end());
            return;
        }
        // processing part
        if(i>n) return;
        
            temp.push_back(i);
            partition(i,temp,ans,n-i);
            temp.pop_back();
            
        partition(i+1,temp,ans,n);
    }
    vector<vector<int>> UniquePartitions(int n) {
        //  create a vector
        vector<int>temp;
        vector<vector<int>>ans;
        partition(1,temp,ans,n);
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Solution ob;
        vector<vector<int>> ans = ob.UniquePartitions(n);
        for (auto i : ans)
            for (auto j : i)
                cout << j << " ";
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends