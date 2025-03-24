//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//User function Template for C++

class Solution {
  public:
    vector<long long> distributeCandies(int N, int K) {
        // code here
        vector<long long> ret;
        for(int i=0; i<K; i++){
            ret.push_back(0);
        }
        int c=1;
        while(N>0){
            for(int i=0; i<K; i++){
                if(N>=c){
                    ret[i]+=c;
                    N-=c;
                    c++;
                }
                else{
                    ret[i]+=N;
                    N=0;
                    break;
                }
            }
        }
        return ret;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        
        Solution ob;
        vector<long long> res = ob.distributeCandies(N,K);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends