//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        map<int,int> m;
        int ans =0;
        int curr =0;
       
        for(int x :arr){
            curr+=x;
            
            if(m.find(curr)!=m.end()){
                ans=ans+m[curr];
            }
            if(curr==0 ){
                ans++;
            }
            m[curr]++;
            // cout<<curr<<" "<<ans<<'\n';
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.findSubarray(arr) << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends