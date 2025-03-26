//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {

  public:
    int repeatedStringMatch(string a, string b) {
       int n=b.size()/a.size()+2;
       int cnt=1;
       string res=a;
       
       for(int i=1;i<=n;i++){
           if(res.find(b)!=string::npos){
               return cnt;
           }
           res+=a;
           cnt++;
       }
       return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A;
        cin >> B;
        Solution obj;
        cout << obj.repeatedStringMatch(A, B) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends