//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function Template for C++

class Solution{
public:
    long buzzTime(long n, long m, long l, long h[], long a[])
    {
        // code here 
        //brute force
        // long speed_on_track=0;
        // for(long i=0;i<10000000000;i++){
        //     for(long j=0;j<n;j++){
            
        //         if(h[j]+a[j]*i>=l)
        //         speed_on_track+=h[j]+a[j]*i;
                
        //         else
        //         continue;
        //     }
            
        //     if(speed_on_track>=m)
        //     return i;
            
        //     else
        //     speed_on_track=0;
        // }
        
        long beg=0,end=10000000000,mid,ans=0,speed_on_track=0;
        
        while(beg<=end){
            
            mid=(beg+end)/2;
            for(long j=0;j<n;j++){
            
                if(h[j]+a[j]*mid>=l)
                speed_on_track+=h[j]+a[j]*mid;
                
                else
                continue;
            }
            
            if(speed_on_track>=m)
            {
                ans=mid;
                end=mid-1;
                speed_on_track=0;
            }
            
            else if(speed_on_track<m)
            {
                speed_on_track=0;
                beg=mid+1;
            }
            
            
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends