//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
  
    void solve(int start, string &s, unordered_set<string> &set, vector<string> &ans, string path){
        if(start == s.length()){
            ans.push_back(path.substr(1));
            return;
        }
        
        for(int end = start+1; end <= s.length(); end++){
            string word = s.substr(start, end- start);
            
            if(set.count(word)){
                solve(end, s, set, ans, path + " " + word);
            }
        }
    } 
    
    vector<string> wordBreak(vector<string>& dict, string s) {
        unordered_set<string> set(dict.begin(), dict.end());
        vector<string> ans;
        
        solve(0, s, set, ans, "");
        
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> dict;
        string s;
        string line;
        getline(cin, line);
        stringstream ss(line);
        while (ss >> s) {
            dict.push_back(s);
        }
        cin >> s;
        cin.ignore();
        Solution ob;
        vector<string> ans = ob.wordBreak(dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends