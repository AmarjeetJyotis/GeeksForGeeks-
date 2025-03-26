//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


// User function template for C++

class Solution {
  public:
    vector<int> factorial(int n) {
        vector<int> ans(1,1);
        int carry;
        
        while(n){
            carry=0;
            for(int i=0;i<ans.size();i++){
                int mul=ans[i]*n+carry;
                ans[i]=mul%10;
                carry=mul/10;
            }
            
            while(carry){
                ans.push_back(carry%10);
                carry/=10;
            }
            n--;
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends