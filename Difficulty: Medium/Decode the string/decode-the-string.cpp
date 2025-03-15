//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends





class Solution {
  public:
    string decodedString(string &s) {
        // code here
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ']') {
                res.push_back(s[i]);
            }
            else {
                string temp = "";
                while (!res.empty() && res.back() != '[') {
                    temp.push_back(res.back());
                    res.pop_back();
                }
                reverse(temp.begin(), temp.end());
                res.pop_back();
                string num = "";
                while (!res.empty() && res.back() >= '0' && res.back() <= '9') {
                    num.push_back(res.back());
                    res.pop_back();
                }
                reverse(num.begin(), num.end());
                int p = stoi(num);
                while (p--) {
                    res.append(temp);
                }
            }
        }
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends