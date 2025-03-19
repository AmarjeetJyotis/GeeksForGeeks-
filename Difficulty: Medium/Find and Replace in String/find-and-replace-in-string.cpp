//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        // code here
        int replacedStringLength = 0;
        for(int i = 0;i<Q;i++){
            string src = sources[i];
            int ind = index[i];
            string tar = targets[i];
            int startingIdx = ind+replacedStringLength;
            if(S.find(src,startingIdx) == startingIdx){
                S.replace(startingIdx,src.length(),tar);
                replacedStringLength += (tar.length() - src.length());
            }
        }
        
        return S;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends