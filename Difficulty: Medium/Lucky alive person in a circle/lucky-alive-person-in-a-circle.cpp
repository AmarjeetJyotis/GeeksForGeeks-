//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
public:
    int find(int N){
        int i=1;
        int ans=0;
        while(i<=N)
        {
            ans=(ans+2)%i;
            i++;
        }
        return ans+1;
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
        cin>>N;
        Solution ob;
        cout << ob.find(N) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends