//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//User function Template for C++

class Solution{
public:
    string LCP(string ar[], int n)
    {
        sort(ar,ar+n);
        string wordOne=ar[0];
        string wordTwo=ar[n-1];
        int i=0;
        int j=0;
        string finalStr="";
        while(i<wordOne.size()&&j<wordTwo.size()){
            if(wordOne[i]!=wordTwo[j]){
                break;
            }
            finalStr+=wordOne[i];
            i++;
            j++;
        }
        if(finalStr.size()==0) return "-1";
        return finalStr;
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
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends