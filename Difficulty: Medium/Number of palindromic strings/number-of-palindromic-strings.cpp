//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function template for C++
class Solution {
  public:

    int palindromicStrings(int n, int k) {
        // Your code goes here
        long long mod = 1e9+7;
        vector<long long> vec(k+1,1);
        int count=k;
        for(int i=1;i<=k;i++){
            vec[i] = (vec[i-1]%mod*(count--)%mod)%mod; 
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            int index = (i+1)/2;
            if(index<=k){
                ans = (ans%mod +  vec[index]%mod)%mod;
            }
            else{
                break;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        Solution ob;

        cout << ob.palindromicStrings(n, k) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends