//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
private:
    int f(int i,vector<int>&arr,int n,int k,int curr,unordered_map<int,unordered_map<int,int>>& dp){
        if(i==n){
            if(curr==k){
                return 1;
            }
            return 0;
        }
        if(dp[i].count(curr)){
            return dp[i][curr];
        }
        int include=f(i+1,arr,n,k,curr^arr[i],dp);
        int exclude=f(i+1,arr,n,k,curr,dp);
        return dp[i][curr]=include+exclude;
        
    }
public:
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        unordered_map<int,unordered_map<int,int>> dp;
        return f(0,arr,N,K,0,dp);
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends