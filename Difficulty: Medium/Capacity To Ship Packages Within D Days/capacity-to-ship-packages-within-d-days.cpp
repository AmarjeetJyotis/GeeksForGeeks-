//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
  
  
    bool tofind(int arr[],int n,int d,int mid){
        vector<int> res[2];
        int count = 0;
        int dg = 1; 
        
        for(int i=0;i<n;i++){
            
            if(count + arr[i] > mid){
                dg++;
                count = arr[i];
            }
            else{
                count += arr[i];
            }
            
            // if(dg==2 && i==n-1){
            //     return dg;
            // }
        }
        if(dg<=d) return true;
        //return if(dg<=k);
        return false;
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        
        int low = arr[0];
        int high = arr[0];
        for(int i=1;i<n;i++){
            high += arr[i];
            if(low<arr[i]){
                low = arr[i];
            }
        }
        
        //int mini;
        int ans;
        while(low<=high){
            int mid = (low+high)/2;
            
            //int ans = tofindmax(arr,n,d);
            
            if(tofind(arr,n,d,mid)){
                 ans = mid;
                 high = mid-1;
                 
            }
            else{
                low = mid+1;
               
            }
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends