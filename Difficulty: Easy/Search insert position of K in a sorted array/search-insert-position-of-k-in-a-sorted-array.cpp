//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>arr, int N, int k)
    {
        // code here
        int ans,num = arr[0];
        int low = 0,high = arr.size()-1;
        if(k<=num){
            return 0;
        }
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid] < k && arr[mid] >= num){
                ans = mid;
                num = arr[mid];
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return ans + 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends