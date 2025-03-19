//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
	{   
	    int n = s.size();
	    vector<int>LPS(n);
	    
	    LPS[0]=0;
	    
	    int i=0;
	    int j=1;
	    
	    while(j < n){
	        if(s[i]==s[j]){
	            LPS[j] = i + 1;
	            i++;
	            j++;
	        }
	        else{
	            if(i==0){
	                LPS[j] = 0;
	                j++;
	            }
	            else{
	                i = LPS[i-1];
	            }
	        }
	    }
	    
	    if(LPS[n-1] == 0) return false;
	    
	    return !(n%(n-LPS[n-1]));
	    
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends