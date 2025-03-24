//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s1, string &s2) {
        // Your code here
        int n = s1.length();
        int m = s2.length();
        if(m>n) return "";
        unordered_map<char, int>window_freq, s2_freq;
        for(auto s : s2) s2_freq[s]++;
        
        int minLen = INT_MAX, minStart = -1;
        int l = 0, r = 0, count = 0;
        while(r<n){
            char rightChar = s1[r];
            window_freq[rightChar]++;
            if(s2_freq[rightChar]>0 && window_freq[rightChar]<=s2_freq[rightChar]){
                count++;
            }
            
            // if window has all char of s2
            while(count==m){
                if(r-l+1<minLen){
                    minLen = r-l+1;
                    minStart = l;
                }
                char leftChar = s1[l];
                window_freq[leftChar]--;
                
                if(s2_freq[leftChar]>0 && window_freq[leftChar]<s2_freq[leftChar]){
                    count--;
                }
                l++;
            }
            
            r++;
        }
        return (minLen == INT_MAX) ? "": s1.substr(minStart, minLen);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        Solution obj;
        string str = obj.smallestWindow(s1, s2);
        if (str.size() == 0) {
            cout << "\"\"" << endl;
        } else {
            cout << str << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends