//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        int start = 0, end = k - 1;
        vector<int> result;
        vector<int> negatives; 


        for (int i = start; i <= end; i++) {
            if (arr[i] < 0) {
                negatives.push_back(arr[i]);
            }
        }


        result.push_back(negatives.empty() ? 0 : negatives.front());


        while (end < n - 1) {
            end++;  


            if (arr[end] < 0) {
                negatives.push_back(arr[end]);
            }


            if (!negatives.empty() && arr[start] == negatives.front()) {
                negatives.erase(negatives.begin());
            }

            start++;  
            
            result.push_back(negatives.empty() ? 0 : negatives.front());
        }

        return result;
    }
};



//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.firstNegInt(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends