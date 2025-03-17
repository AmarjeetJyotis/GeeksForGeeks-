//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

// User function Template for C++

class Solution{
public:

vector<long long int> minimumSquares(long long int L, long long int B) {
    // Find the greatest common divisor (GCD) of L and B
    long long int K = __gcd(L, B);
    
    // Calculate the number of such squares
    long long int N = (L * B) / (K * K);
    
    // Return the results as a vector
    return {N, K};
}


};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int L, B;
        cin>>L>>B;
        
        Solution ob;
        vector<long long int> ans = ob.minimumSquares(L, B);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends