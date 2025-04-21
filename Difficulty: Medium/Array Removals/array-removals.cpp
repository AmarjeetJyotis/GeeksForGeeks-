//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++


class Solution{
    public:
    int removals(vector<int>& arr, int k){
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int i=0;
        int maxlen=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]-arr[i]>k)
            {
                i++;
            }
            maxlen=max(maxlen,(j-i)+1);
        }
        return n-maxlen;
    }
};



//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    
cout << "~" << "\n";
}
}



// } Driver Code Ends