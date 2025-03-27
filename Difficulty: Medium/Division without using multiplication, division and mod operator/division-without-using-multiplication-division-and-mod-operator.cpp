//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//User function Template for C++

class Solution
{
    public:
    long long divide(long long y, long long x) 
    {
        //code here
        int sign = ((y<0)^(x<0)) ? -1:1;
        y = abs(y);
        x = abs(x);
        
        long long ans = 0;
        while(y>=x){
            int i=0;
            while(1){
                long long int t = x*(1<<i);
                if(y<t) break;
                
                i++;
            }
            i--;
            long long p = 1<<i;
            ans+=p;
            long long r = y-x*p;
            y=r;
        }
        
        return sign*ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	
cout << "~" << "\n";
}

	return 0;
}

// } Driver Code Ends