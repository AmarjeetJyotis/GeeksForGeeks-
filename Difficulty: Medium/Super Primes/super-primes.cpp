//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//User function template for C++
class Solution{
public:	
	bool isprime(int n)
	{
	    if(n == 2) return true;
	    if(n % 2 == 0) return false;
	    while(n % 2 == 0) n/=2;
	    for(int i = 3;i <= sqrt(n);i++)
	    {
	        if(n % i == 0) return false;
	        while(n % i == 0) n /=i;
	    }
	    return true;
	}
	
	int superPrimes(int n)
	{
	    int cnt = 0;
	    for(int i = 2;i <= n;i++)
	    {
	        if(isprime(i) and isprime(i+2) and (i+2) <= n)
	        {
	            cnt++;
	        }
	    }
	    return cnt;
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
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends