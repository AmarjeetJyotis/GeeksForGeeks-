//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

// User function Template for C++
#define ll long long
long long int no_of_subarrays(int n, vector<int> &nums) {
        ll ans = 0;
        for(int i=0;i<n;){
            if(nums[i]==0){
                ll count = 0;
                while(i<n){
                    if(nums[i]==0){
                        count++;
                    }
                    else{
                        break;
                    }
                    i++;
                }
                count*=(count+1);
                count/=2;
                ans+=count;
            }
            else{
                i++;
            }
        } 
        return ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends