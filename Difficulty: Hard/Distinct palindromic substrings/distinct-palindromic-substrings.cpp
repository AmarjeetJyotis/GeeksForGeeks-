//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function template for C++

class Solution{
  public:
  
    void expand(string &s, int i, int j, unordered_set<string> &uniquePalindromes) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            uniquePalindromes.insert(s.substr(i, j - i + 1)); // Store unique palindrome
            i--;
            j++;
        }
    }
    
    int palindromeSubStrs(string s) {
          unordered_set<string> uniquePalindromes;
        for(int center=0;center<s.length();center++){
            expand(s, center, center, uniquePalindromes);     // Odd-length palindromes
            expand(s, center, center + 1, uniquePalindromes); // Even-length palindromes
        }
         return uniquePalindromes.size();
    }
};


//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends