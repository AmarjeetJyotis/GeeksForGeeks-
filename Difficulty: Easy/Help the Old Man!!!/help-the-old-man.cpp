//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function Template for C++

class Solution{
public:
    vector<int> res;
    int cnt = 0;
    void do1(int n, int from, int to) {
        ++cnt;
        if (cnt == n) {
            res.push_back(from);
            res.push_back(to);
            return;
        }
    }
    void do2(int N, int n, int from, int aux, int to) {
        if (N >= 1 && cnt < n) {
            do2(N - 1, n, from, to, aux);
            do1(n, from, to);
            if (res.size()) {
                return;
            }
            do2(N - 1, n, aux, from, to);
        }
    }
    vector<int> shiftPile(int N, int n){
        // code here
        do2(N, n, 1, 2, 3);
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends