//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    int getCount(int n) {
       int j=0;
        int k=0,i=1;
        while(n>0){
            n=n-i;
            if(n%i==0) k++;
            i++;
            
        }
        return k-1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.getCount(N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends