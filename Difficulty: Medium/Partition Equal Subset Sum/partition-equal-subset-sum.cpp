//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  
  bool handler(vector<int>&arr,int target,int currSum,int indx){
      if(currSum==target) return true;
      if(indx==0) return false;
      
      int pick=false;
      if(currSum+arr[indx-1]<=target){
          pick=handler(arr,target,currSum+arr[indx-1],indx-1);
      }
      
      int notPick=handler(arr,target,currSum,indx-1);
      
      return pick || notPick;
  }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=0,n=arr.size();
        for(int it:arr){
            sum+=it;
        }
        
        if(sum%2!=0) return false;
        
        // return handler(arr,sum/2,0,n);
        int target=sum/2;
       // vector<vector<int>>dp(n+1,vector<int>(target+1,false));
       vector<int>curr(target+1,false),prev(target+1,false);
       prev[target]=curr[target]=true;
        
        // for(int indx=0;indx<=n;indx++){
        //     dp[indx][target]=true;
        // }
        
        for(int indx=1;indx<=n;indx++){
            for(int currSum=target-1;currSum>=0;currSum--){
                int pick=false;
      if(currSum+arr[indx-1]<=target){
          pick=prev[currSum+arr[indx-1]];
      }
      
      int notPick=prev[currSum];
      
     curr[currSum]= pick || notPick;
            }
            prev=curr;
        }
        return curr[0];
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends