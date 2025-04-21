//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int a[], int n, int k) {
        unordered_map<int,int>f;

        for(int i=0;i<n;i++){

            a[i]=a[i]%k;

            f[a[i]]++;

        }

        int maxi=0;

        for(int i=1;i<(k+1)/2;i++){

            maxi+=max(f[k-i],f[i]);

        }

        if(f[k/2]>0 && k%2==0){

            maxi+=1;

        }

        if(f[0]>0){

            maxi+=1;

        }

        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends