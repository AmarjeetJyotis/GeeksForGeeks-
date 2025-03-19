//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    int countDistinctSubarray(int arr[], int n){
        unordered_map<int,int>fr;
        unordered_map<int,bool>mp;
        int un=0,ans=0;
        for(int i=0;i<n;i++){
            if(!mp[arr[i]]){
                mp[arr[i]]=true;
                un++;
            }
            mp[arr[i]]=true;
            fr[arr[i]]=0;
        }
        int i=0,j=0,cu=0;
        while(i<n){
            if(fr[arr[i]]==0) cu++;
            fr[arr[i]]++;
            while(cu==un){
                ans+=(n-i);
                fr[arr[j]]--;
                if(fr[arr[j]]==0)cu--;
                j++;
            }
            i++;
        }
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
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends