//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends

class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        // code here
        int cnt=0;
        
       priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);
    
    
    if (pq.top() >= k) {
        return 0;
    }

   
    while (pq.size() > 1 && pq.top() < k) {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        pq.push(a + b);
        cnt++;
    }

   
    return (pq.top() >= k) ? cnt : -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends