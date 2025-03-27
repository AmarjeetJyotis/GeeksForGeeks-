//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
    
    public:
    
    string reverseWords(string &s) {
        
        int n = s.size() ;
        string result ;
        stack<char> st ;
        
        for(int i = 0 ; i < n ; i++)
            if(s[i] != ' ')
                st.push(s[i]) ;
            else {
                bool found = st.empty() ? false : true ;
                while(!st.empty()) {
                    result.push_back(st.top()) ;
                    st.pop() ;
                }
                if(found) result.push_back(' ') ;
            }
            
        while(!st.empty()) {
            result.push_back(st.top()) ;
            st.pop() ;
        }
        
        if(result.back() == ' ') result.pop_back() ;
        
        return result ;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;     // Read the number of test cases
    cin.ignore(); // Consume the newline character after reading the integer

    while (t--) {
        string s;
        getline(cin, s); // Read the string input

        string str = s.substr(1, s.size() - 2); // Remove surrounding quotes
        Solution obj;                       // Create an object of the Solution class
        string ans = obj.reverseWords(str); // Reverse the words in the string
        cout << '"';                        // Print opening quote
        cout << ans;                        // Print the result
        cout << '"';                        // Print closing quote
        cout << endl;                       // Print a newline
    }
    return 0; // Return 0 to indicate successful execution
}

// } Driver Code Ends