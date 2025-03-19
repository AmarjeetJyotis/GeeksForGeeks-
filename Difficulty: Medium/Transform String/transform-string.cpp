//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        unordered_map<int,int>mp;
        for(int i=0;i<A.length();i++){
            mp[A[i]]++;
        }
        for(int j=0;j<B.length();j++){
            mp[B[j]]--;
        }
        for(auto i:mp){
            if(i.second!=0) return -1;
        }
        int i=A.length()-1,j=B.length()-1;
        
        int c=0;
        while(i>=0 && j>=0){
            if(A[i]==B[j]){
                i--;
                j--;
            }
            else{
                c++;
                i--;
            }
        }
        if(j==B.length()-1) return -1;
        return c;
    }
};



//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends