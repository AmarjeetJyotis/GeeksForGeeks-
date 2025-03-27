//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends




class Solution {
    vector<string>  mp = {"", "", 
    "abc","def","ghi", "jkl", "mno", 
    "pqrs", "tuv", "wxyz"};
    void f(int ind, vector<string>&ans, vector<int> &arr, string &ds){
        if(arr.size() == ind) {
            ans.push_back(ds);
            return;
        }
        
        string curr = mp[arr[ind]];
        for(int i=0; i<curr.size(); i++) {
            ds.push_back(curr[i]);
            f(ind+1, ans, arr, ds);
            ds.pop_back();
        }
    }
  public:
    vector<string> possibleWords(vector<int> &arr) {
        if(arr.size() == 0) { return {}; }
        vector<string> ans;
        string ds;
        f(0, ans, arr, ds);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        vector<string> v = obj.possibleWords(a);
        sort(v.begin(), v.end());
        Array::print(v);
        cout << "~" << endl;
    }
}

// } Driver Code Ends