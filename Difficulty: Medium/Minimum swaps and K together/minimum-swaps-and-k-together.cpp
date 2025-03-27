//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        int n=arr.size(),elementsSmallerThanK=0,continuosCount=0,maxContinuosCount=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                elementsSmallerThanK++;
                continuosCount++;
                maxContinuosCount=max(continuosCount,maxContinuosCount);
            }
            else{
                continuosCount=0;
            }
        }
        
        return elementsSmallerThanK-maxContinuosCount;
    }
};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.minSwap(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends