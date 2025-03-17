//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        int cnt=0;
        vector<bool>visited(leaves+1,false);
    for (int i=0;i<N;i++) {
        int strength=frogs[i];
        // Skip already marked frogs or too strong
        if (strength > leaves ||visited[strength]==true) continue;

        // Mark all leaves visited by current frog
        for (int j=strength;j<=leaves;j+=strength) {
            visited[j]=true;
        }
    }
        for(int i=1;i<=leaves;i++){
            if(!visited[i])cnt++;
        }
        return cnt;
    }
};



//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends