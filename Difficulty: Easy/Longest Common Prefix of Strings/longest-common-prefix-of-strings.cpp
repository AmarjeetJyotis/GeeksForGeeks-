//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        if(arr.size()==0) return "";
        
        sort(arr.begin(),arr.end());
        string first=arr[0];
        string last=arr[arr.size()-1];
        int i=0;
        while(i<first.size() && i<last.size() && first[i]==last[i]){
            i++;
        }
        return first.substr(0,i);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        string ans = ob.longestCommonPrefix(arr);
        if (ans.empty())
            cout << "\"\"";
        else
            cout << ans;
        cout << endl;
    }
}

// } Driver Code Ends