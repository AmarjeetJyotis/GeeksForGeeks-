//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
  public:
    char firstRep (string s)
    {
        //code here.
        int k = s.size();
        for(int i=0; i<k;i++){
            for(int j=i+1; j<k; j++){
                if(s[i]==s[j]){
                    return s[i];
                    break;
                }
            }
        }
        return '#';
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    
cout << "~" << "\n";
}
    return 0;
}



// } Driver Code Ends