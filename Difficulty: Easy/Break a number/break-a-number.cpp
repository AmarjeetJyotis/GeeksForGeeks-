//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


//User function Template for C++
class Solution{   
public:
    int waysToBreakNumber(int N){
       long long int ans = N+1;
       int mod=1e9+7;
       
        return ((ans*(ans+1)/2))%mod;
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
        cin >> N;
        Solution ob;
        cout << ob.waysToBreakNumber(N) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 
// } Driver Code Ends