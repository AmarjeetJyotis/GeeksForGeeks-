//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> permute(vector<vector<int>> &arr, int n);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> arr(n);
        
        for(int i=0;i<n;i++)
        {
            int a, b;
            cin>> a>> b;
            arr[i].push_back(a);
            arr[i].push_back(b);
        }
        
        vector<int> ans;
        ans = permute(arr, n);
        for(int i=0;i<n;i++)
            cout << ans[i] << "\n";
        
    
cout << "~" << "\n";
}
    
	return 0;
}
// } Driver Code Ends




vector<int> permute(vector<vector<int>> &arr, int n)
{
    
    // Complete the function
    vector<pair<int,int>> ans;
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=0;j<arr[i].size();j++){
            sum+=arr[i][j];
        }
        ans.push_back({sum,i});
    }
    sort(ans.begin(),ans.end());
    vector<int> res;
    for(auto x: ans){
        res.push_back(x.second+1);
    }
    return res;
    
}