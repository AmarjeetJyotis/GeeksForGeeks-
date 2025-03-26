//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function Template for C++

class Solution{
public:
    vector<int> segTree;
    
    void buildTree(int idx,int l,int r,int arr[]) {
        if(l==r) {
            segTree[idx] = arr[l];
            return;
        }
        
        int mid = (l + (r-l)/2);
        //leftchild
        buildTree(2*idx+1,l,mid,arr);
    
        // right child
        buildTree(2*idx+2,mid+1,r,arr);
        
        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
    }
    
    int Query(int start,int end,int idx,int l,int r,int arr[]) {
        //out of bound
        if(l>end or r<start) {
            return 0;
        }
        
        if(l>=start and r<=end) {
            return segTree[idx];
        }
        int mid = l+(r-l)/2;
        
        return Query(start,end,2*idx+1,l,mid,arr) + Query(start,end,2*idx+2,mid+1,r,arr);
    }
    
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {  
       segTree.resize(4*n);
       buildTree(0,0,n-1,arr);
       
       vector<int> ans;
       for(int i=0;i<2*q;i+=2) {
           int start = queries[i] - 1;
           int end = queries[i+1] -1;
           ans.push_back(Query(start,end,0,0,n-1,arr));
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];
        
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends