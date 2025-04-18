//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function Template for C++


class Solution{
  public:
long long int wineSelling(vector<int>& arr, int n){
      //Code here.
     queue <pair<int,int>> positive; //{positivevalue,index}
     queue <pair<int,int>> negative; //{negative value,index}
     long long int ans=0;
     
      for(int i=0;i<n;i++){
          if(arr[i]<0)
          negative.push({arr[i],i});
          else 
          positive.push({arr[i],i});
      }
      
      while(!positive.empty() && !negative.empty()){
          int pos=positive.front().first;
          int neg=negative.front().first;
          
          if(pos >= abs(neg)){
            ans=ans+ (abs(neg) * (abs(negative.front().second - positive.front().second)));
            positive.front().first= (pos) + (neg);
            negative.pop(); 
          }
          else if(pos < abs(neg)){
              ans=ans+ (pos * (abs(negative.front().second - positive.front().second)));
            negative.front().first= (neg) + (pos);
            positive.pop();
          }
          if (positive.front().first == 0)
            positive.pop(); 
        if (negative.front().first == 0)
            negative.pop();
      }
      return ans; 
  }
};





//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends