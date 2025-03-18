//{ Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


// } Driver Code Ends


class Solution{
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        vector<int> ans(n,-1);
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        stack<int> st;
        int mx=0,ele=-1;
        for(int i=n-1;i>=0;i--){
            if(st.empty()) ans[i]=-1;
            else{
                while(!st.empty()&&mp[st.top()]<=mp[arr[i]]){
                    st.pop();
                }
                if(st.empty()) ans[i]=-1;
                else ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
	return 1;
}

// } Driver Code Ends