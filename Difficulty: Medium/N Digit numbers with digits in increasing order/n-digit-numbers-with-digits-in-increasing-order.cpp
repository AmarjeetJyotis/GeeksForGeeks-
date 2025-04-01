//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++
class Solution {
  public:
  
    void fun(int n,int out,vector<int> &v)
    {
        if(n==0)
        {
            v.push_back(out);
            return;
        }
        for(int i=out%10+1;i<10;i++)
        {   
            out=out*10+i;
            fun(n-1,out,v);
            out/=10;
        }
        
        
        
    }
    vector<int> increasingNumbers(int n) {
        vector<int> v;
        if(n==1)
            v.push_back(0);
        
        fun(n,0,v);
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends