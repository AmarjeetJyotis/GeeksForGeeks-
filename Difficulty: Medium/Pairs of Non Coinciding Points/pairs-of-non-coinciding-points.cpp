//{ Driver Code Starts
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
       unordered_map<int,int>xp;
       unordered_map<int,int>yp;
       unordered_map<int,int>checkx;
       unordered_map<int,int>checky;
       int ans=0;
       for(int i=0;i<N;i++){
           if(xp.find(X[i])!=xp.end() && checkx[X[i]]!=Y[i] ){
               ans+=xp[X[i]];
           }
           if(yp.find(Y[i])!=yp.end() && checky[Y[i]]!=X[i]){
               ans+=yp[Y[i]];
           }
          xp[X[i]]++;
          yp[Y[i]]++;
          checkx[X[i]]=Y[i];
          checky[Y[i]]=X[i];
       }
       return ans;
   }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends