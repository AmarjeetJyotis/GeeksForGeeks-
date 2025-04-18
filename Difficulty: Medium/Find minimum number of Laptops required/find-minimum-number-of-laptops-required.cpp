//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//User function Template for C++

class Solution {
  public:
  int minLaptops(int N, int start[], int end[]) {
        // Code here
        if(N==1){
            return 1;
        }
        sort(start,start+N);
        sort(end,end+N);
        int sTime=0; //S[]={1,1,2,4,8}
        int eTime=0; //E[]={2,3,4,6,9}
        int laptops=N; //Total laptops 5
        while(sTime<N){
            if(end[eTime]<=start[sTime]){// 2<=2 , 3<4 , 4<8
                laptops--; //5-- , 4--, 3-- =2 
             //laptop=N-No. of allocations if endTime<=startTime 
                eTime++;
            }
            sTime++;
        }
        return laptops; //2
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends