//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    int kThSmallestFactor(int n, int k) {
        // code here
        for(int i=1;i<=sqrt(n);i++){
      if(n%i==0) k--;
      if(k==0) return i;

    }
    for(int i=sqrt(n);i>0;i--){
 if(i*i==n) continue;
   
   if(n%(n/i)==0) k--;

   if(k==0) return n/i;
    }
    return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;

        cin >> N >> K;

        Solution ob;
        cout << ob.kThSmallestFactor(N, K) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends