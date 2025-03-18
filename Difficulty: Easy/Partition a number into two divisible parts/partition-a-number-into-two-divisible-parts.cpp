//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution{   
public:
    string stringPartition(string S, int a, int b){
        // code here 
        int i;
       // string tmp1, tmp2;
        for (i=1;i<S.size();i++)
        {
            int tpA = stoi(S.substr(0,i));
            int tpB = stoi(S.substr(i));
            if ((tpA % a) == 0 && (tpB %b) ==0)
            {
                return S.substr(0,i) +" "+ S.substr(i);
            }
        }
        return "-1";
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 
// } Driver Code Ends