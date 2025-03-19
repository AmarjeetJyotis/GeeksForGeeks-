//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        vector<pair<int, int>> boxes(N);
        for (int i = 0; i < N; i++) {
            boxes[i] = {B[i], A[i]};
        }

        sort(boxes.rbegin(), boxes.rend());

        int maxGold = 0;
        for (int i = 0; i < N && T > 0; i++) {
            int platesTaken = min(T, boxes[i].second);
            maxGold += platesTaken * boxes[i].first;
            T -= platesTaken;
        }

        return maxGold;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends