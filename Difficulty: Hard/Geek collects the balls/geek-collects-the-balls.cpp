//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++


// User function Template for C++

class Solution {
  public:
    int maxBalls(int n, int m, vector<int> a, vector<int> b) {
        int i=n-1;
        int j=m-1;
        vector<int>ra(n+1,0);
        vector<int>rb(m+1,0);
        while(i>=0&&j>=0)
        {
            if(a[i]>b[j])
            {
                ra[i]=ra[i+1]+a[i];
                i--;
            }
            else if(a[i]==b[j])
            {
                ra[i]=max(ra[i+1],rb[j+1])+a[i];
                rb[j]=max(ra[i+1],rb[j+1])+b[j];
                i--;
                j--;
            }
            else
            {
                rb[j]=rb[j+1]+b[j];
                j--;
            }
        }
        while(i>=0)
        {
            ra[i]=ra[i+1]+a[i];
            i--;
        }
        while(j>=0)
        {
            rb[j]=rb[j+1]+b[j];
            j--;
        }
        return max(ra[0],rb[0]);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<int> a(N), b(M);
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = 0; i < M; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.maxBalls(N, M, a, b) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends