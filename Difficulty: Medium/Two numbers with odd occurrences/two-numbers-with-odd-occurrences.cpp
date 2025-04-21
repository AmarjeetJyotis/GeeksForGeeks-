//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long x=0;
        for(int i=0; i<N; i++)
            x = x ^ Arr[i];
        int f = 1;
        while(!(x & f)){
            f = f << 1;
        }
        vector<long long> a1, a2;
        for(int i=0; i<N; i++){
            if(Arr[i] & f)
                a1.push_back(Arr[i]);
            else
                a2.push_back(Arr[i]);
        }
        vector<long long int> ans;
        long long a=x,b=x;
        
        for(auto v: a1)
            a=a^v;
        for(auto v: a2)
            b=b^v;
        ans.push_back(a);
        ans.push_back(b);
        sort(ans.begin(), ans.end(), greater<long long int>());
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends