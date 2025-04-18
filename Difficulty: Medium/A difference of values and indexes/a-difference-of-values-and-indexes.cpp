//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends


class Solution{
  public:
     int maxDistance(int arr[], int n) 
    { 
        // Complete the function
      long ind=n-1,ma=arr[n-1];
      long res=0;
      for(int i=n-1;i>=0;i--){
          res=max(res,abs(arr[i]-ma)+abs(ind-i));
         // if(arr[i]>0)continue;
          if(arr[i]<ma+i-ind)ind=i,ma=arr[i];
      }
      ind=n-1,ma=arr[n-1];
        for(int i=n-1;i>=0;i--){
          res=max(res,abs(ma-arr[i])+abs(ind-i));
          if(arr[i]>ma+ind-i)ind=i,ma=arr[i];
      }
      
        return res;
    }  
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	
cout << "~" << "\n";
}
} 

// } Driver Code Ends