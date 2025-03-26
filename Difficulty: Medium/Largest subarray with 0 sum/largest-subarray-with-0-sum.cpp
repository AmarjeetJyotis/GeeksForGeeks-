//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> prefixSumIndex;
        int prefixSum = 0;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            prefixSum+=arr[i];
            if(prefixSum==0) maxLen=i+1;
            if(prefixSumIndex.find(prefixSum)!=prefixSumIndex.end()){
                maxLen=max(maxLen,i-prefixSumIndex[prefixSum]);
            }
            else{
                prefixSumIndex[prefixSum]=i;
            }
        }
        return maxLen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends