//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> search(string& pat, string& text) {
        int n = text.size();
        int m = pat.size();
        
        vector<int> lps(m, 0);
        
        int len = 0;
        lps[0] = 0;
        
        int i = 1;
        while(i < m){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    i++;
                }
            }
        }
        
        i = 0;
        int j = 0;
        
        vector<int> ans;
        
        while(i < n){
            if(text[i] == pat[j]){
                i++;
                j++;
            }
            if(j == m){
                ans.push_back(i-j);
                j = lps[j-1];
            }
            else if(text[i] != pat[j]){
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends