//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends


//User function template for C++

class Solution {
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
            // code here 
            map<int,int> mp1,mp2;
            
            for(int i=0;i<n;i++){
                if(mp1[arr2[i]]==0) mp1[arr2[i]] = i+1;
            }
            for(int i=0;i<n;i++){
                if(mp1[arr1[i]]==0) mp1[arr1[i]]=n+i+1;
            }

            
            int j=0;
            
            
            for(auto it=mp1.rbegin();it!=mp1.rend() && j<n;it++,j++){
                mp2[it->second]=it->first;
            }
            
            vector<int> res;
            
            for(auto el:mp2){
                res.push_back(el.second);
            }
            
            return res;
            
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maximizeArray(arr1, arr2, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends