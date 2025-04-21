//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    priority_queue<int> eraseMx(priority_queue<int> pq, int ele){
        priority_queue<int> temp;
        while(!pq.empty()){
            if(pq.top() != ele) temp.push(pq.top());
            
            pq.pop();
        }
        return temp;
    }
    
    priority_queue<int, vector<int>, greater<int>> eraseMn(priority_queue<int, vector<int>, greater<int>> pq, int ele){
        priority_queue<int, vector<int>, greater<int>> temp;
        while(!pq.empty()){
            if(pq.top() != ele) temp.push(pq.top());
            
            pq.pop();
        }
        return temp;
    }
  
    int longestPerfectPiece(int arr[], int N) {
        priority_queue<int> mx;
        priority_queue<int, vector<int>, greater<int>> mn;
        int start = 0;
        int ans = 0;
        for(int i=0;i<N;i++){
            mn.push(arr[i]);
            mx.push(arr[i]);
            while((mx.top() - mn.top() > 1) && (start < N)){
                mx = eraseMx(mx,arr[start]);
                mn = eraseMn(mn, arr[start]);
                start++;
            }
            ans = max(ans, i - start+1);
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
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends