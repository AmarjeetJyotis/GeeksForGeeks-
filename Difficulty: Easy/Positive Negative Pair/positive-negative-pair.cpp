//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
#include <math.h>
using namespace std;


// } Driver Code Ends


// User function template for C++

class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) 
    {
        // code here
        unordered_set<int> seen;
        vector<int>result;
        for(int i = 0; i < n; ++i) {
            int num = arr[i];
            if (seen.find(-num) != seen.end()) {
                if (num < 0) {
                    result.push_back(num);
                    result.push_back(-num);
                } else {
                    result.push_back(-num);
                    result.push_back(num);
                }
                seen.erase(-num);
            } else {
                seen.insert(num);
            }
        }
        if (result.empty()) {
            return {0};
        } else {
            return result;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        vector <int> res = obj.findPairs(arr, n);
    	if(res.size()!=0)
    	{
    		for (int i : res) 
            	cout << i << " ";
        	cout << endl;	
    	}
    	else
    		cout<<0<<endl;
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends