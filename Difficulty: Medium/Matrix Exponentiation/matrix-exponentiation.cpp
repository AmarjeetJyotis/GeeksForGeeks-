//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
       void multiply(int A[2][2], int B[2][2]) {
        const int MOD = 1e9 + 7;
        
        int x = ((long long)A[0][0]*B[0][0] + (long long)A[0][1]*B[1][0]) % MOD;
        int y = ((long long)A[0][0]*B[0][1] + (long long)A[0][1]*B[1][1]) % MOD;
        int z = ((long long)A[1][0]*B[0][0] + (long long)A[1][1]*B[1][0]) % MOD;
        int t = ((long long)A[1][0]*B[0][1] + (long long)A[1][1]*B[1][1]) % MOD;

        A[0][0] = x;
        A[0][1] = y;
        A[1][0] = z;
        A[1][1] = t;
    }
    void power(int A[2][2], int p) {
        if (p==1) return;
        int M[2][2] = {{1,1}, {1,0}};
        
        power(A, p >> 1);
        multiply(A, A);
        
        if(p&1) multiply(A, M);
    }
    int FindNthTerm(long long int n) {
        // Code here
        int F[2][2] = {{1,1}, {1,0}};
        power(F, n);
        return F[0][0];
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends