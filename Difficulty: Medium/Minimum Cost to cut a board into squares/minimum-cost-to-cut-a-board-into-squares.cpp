//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        sort(begin(X), end(X), greater<int>());
        sort(begin(Y), end(Y), greater<int>());
        int i=0, j=0, V=0, H=0, ans=0;
        while(i<M-1 or j<N-1){
            if(j==N-1 or (i<M-1 and X[i]>Y[j])){
                ans+=X[i++]*(H+1);
                ++V;
            }
            else{
                ans+=Y[j++]*(V+1);
                ++H;
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
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
	    cout << ans<<endl;
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends