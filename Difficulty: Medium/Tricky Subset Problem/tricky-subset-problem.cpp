//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int isPossible(long long S, long long N, long long X, long long A[])
    {
        long long pre=S;
        vector<long long >v;
        v.push_back(S);
        for(int i=0;i<N;i++)
        {
           long long add;
           add=pre+A[i];
           v.push_back(add);
           pre=pre+add;
           if(add>X) break;
          
        }
        int j=v.size()-1;
        while(j>=0)
        {
            if(v[j]<=X)
            {
                X-=v[j];
            }
            j--;
        }
        if(X==0) return 1;
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends