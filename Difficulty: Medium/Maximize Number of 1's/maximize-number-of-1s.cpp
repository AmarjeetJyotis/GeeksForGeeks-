//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
        int n=arr.size();
        int cntzero=0;
        int cntmax=0;
        int i=0;
        int j=0;
        while(j<n){
            if(arr[j]==0){
                cntzero++;
            }
            
            while(cntzero>k){
                if(arr[i]==0){
                    cntzero--;
                }
                i++;
            }
            cntmax=max(cntmax,j-i+1);
            j++;
        }
        return cntmax;
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int m;
        cin >> m;
        cin.ignore();

        Solution obj;
        int ans = obj.maxOnes(arr, m);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends