//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    long long int killinSpree(long long int n)
    {
        long long left = 1, right = 1e6;
        long long ans = -1;
        
       while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long totalStrength = (mid * (mid + 1) * (2 * mid + 1)) / 6;
    
            if (totalStrength <= n) {  // check if total strength is within limit
                ans = mid;  // update answer
                left = mid + 1;  // try for more people
            } else {
                right = mid - 1;  // reduce search space
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends