//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_set>
using namespace std; 

// } Driver Code Ends


class Solution {
public:
    int candies(int m, int n) {
        int sz = n * m + 1;
        bool dp[sz]{false};
        dp[0] = true;
        for (int i = 0; i < sz; ++i) {
            if (!dp[i]) continue;
            if (i + n < sz) dp[i + n] = true;
            if (i + m < sz) dp[i + m] = true;
        }
        
        int res = 0;
        for (int i = 0; i < sz; ++i) {
            if (!dp[i]) ++res;
        }
        return res;
    } 
};


//{ Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		Solution obj;
		cout << obj.candies(m,n)<<endl; 
	
cout << "~" << "\n";
}
	return 0; 
} 




// } Driver Code Ends