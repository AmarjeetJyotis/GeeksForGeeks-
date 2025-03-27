//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    
    public:
   int RulingPair(vector<int> arr, int n) {
    //   jai shree krishn
    unordered_map<int, int> digitSumMap;
    int maxRul = -1; // Default -1 if no valid pair found

    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int sumDigits = 0;
        
        // Calculate digit sum
        while (num > 0) {
            sumDigits += num % 10;
            num /= 10;
        }

        // If this digit sum already exists in map, update maxRul
        if (digitSumMap.find(sumDigits) != digitSumMap.end()) {
            maxRul = max(maxRul, digitSumMap[sumDigits] + arr[i]);
        }

        // Update the map with max value for this digit sum
        digitSumMap[sumDigits] = max(digitSumMap[sumDigits], arr[i]);
    }

    return maxRul;
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
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
	    Solution obj;
		cout << obj.RulingPair(arr,n)<<"\n";
	
cout << "~" << "\n";
}
	return 0; 
} 


// } Driver Code Ends