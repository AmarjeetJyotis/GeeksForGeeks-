//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
  
  
  int solve(int Arr[], int N, int range){
       long long ans = 0;
        for(int i = 0; i<N-2; i++){
            long long s = i+1;
            long long e = N-1;
            
            while(s < e){
             int temp = Arr[i] + Arr[s] + Arr[e];
                if(temp < range) {
                    ans = ans + (e-s);
                    s++;
                }
                else {
                    e--;
                }
                
            }
        }
        return ans;
  }
    int countTriplets(int Arr[], int N, int L, int R) {
        // code here
       sort(Arr, Arr+N);
       return solve(Arr, N, R+1) - solve(Arr, N, L);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends