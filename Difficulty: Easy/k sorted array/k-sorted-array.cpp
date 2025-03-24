//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        vector<pair<int,int>>temp;
        
        for (int i=0;i<n;i++) {
            temp.push_back({arr[i],i});
        }
        sort(temp.begin(),temp.end());
        
        for (int i=0;i<n;i++) {
            int temp1 = temp[i].second;
            if (abs(i-temp1)>k) {
                return "No";
            }
        }
        return "Yes";
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>k;
	    Solution ob;
	cout <<ob.isKSortedArray(arr, n, k)<<endl;
	
cout << "~" << "\n";
}
	return 0;	 
}
// } Driver Code Ends