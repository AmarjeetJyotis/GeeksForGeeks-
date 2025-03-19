//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Function to return Largest Number

class Solution
{
    public:
    // Function to return the largest possible number of n digits
    // with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        // If the sum is greater than the maximum possible sum for n digits, return -1
        if (sum > 9 * n) return "-1";

        string result = ""; // To store the result

        // Iterate through n digits
        for (int i = 0; i < n; i++) {
            // Pick the largest possible digit for the current position
            int digit = min(9, sum);

            // Add the digit to the result
            result += to_string(digit);

            // Reduce the sum by the chosen digit
            sum -= digit;
        }

        return result; // Return the resulting largest number
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends