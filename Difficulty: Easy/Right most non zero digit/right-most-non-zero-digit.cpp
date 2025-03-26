//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


//User function template for C++
#define ll long long

class Solution{   
  public:
    int rightmostNonZeroDigit(int N, int A[]){
        // code here 
        int cnt2 = 0, cnt5 = 0;
        ll res = 1;
        for (int i = 0; i < N; i++){
            if (A[i] == 0){
                return -1;
            }
            while(A[i] % 2 == 0){
                cnt2++;
                A[i] /= 2;
            }
            while(A[i] % 5 == 0){
                cnt5++;
                A[i] /= 5;
            }
            res *= 1ll * A[i];
            res %= 100000;
        }
        int tmp = min(cnt2, cnt5);
        cnt2 -= tmp;
        cnt5 -= tmp;
        if (cnt2 > 0){
            while(cnt2--){
                res *= 1ll * 2;
                res %= 100000;
            }
        }
        if (cnt5 > 0){
            while(cnt5--){
                res *= 1ll * 5;
                res %= 100000;
            }
        }
        while(res % 10 == 0){
            res /= 10;
        }
        return res % 10;
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        Solution ob;
        cout << ob.rightmostNonZeroDigit(n, A) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 
// } Driver Code Ends