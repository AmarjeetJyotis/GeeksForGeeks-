//{ Driver Code Starts
// C++ program to find number 
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  int arr[n+1];
	  for( int i=0;i<n;i++)
	        cin>>arr[i];
	    cout << calculate(arr, n)<<endl;
        
	
cout << "~" << "\n";
}
	return 0;
}


// } Driver Code Ends



long long int calculate(int a[], int n)
{
    // Complete the function
    
        if (n < 2) return 0; // No pairs possible if n < 2

    unordered_map<int, long long> freq;
    long long int ans = 0;

    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    // Calculate pairs using nC2 formula: f * (f-1) / 2
    for (auto it : freq) {
        long long f = it.second;
        ans += (f * (f - 1)) / 2; // Number of valid pairs
    }

    return ans;


}
