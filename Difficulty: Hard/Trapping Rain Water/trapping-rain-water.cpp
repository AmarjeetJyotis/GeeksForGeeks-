//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


int Min(int a,int b){
	if(a>b){
		return b;
	}else{
		return a;
	}
}

class Solution {
  public:
    int maxWater(vector<int> &height) {
        // code here
        int heightSize = height.size();
        int max_idx=0;
    // Find the  index of maximum element in the array
	for(int i=1; i<heightSize; i++){
		if(height[max_idx]<height[i]){
			max_idx=i;
		}
	}
	int units=0;
    // 1. from 0 to max_idx-1
    // from 0 to max_idx the right maximum is constant
	int l=height[0];
	int r=height[max_idx];
	for(int i=0; i<max_idx; i++){
		if(l<height[i]){
			l=height[i];
		}
		units+=Min(l,r)-height[i];	
	}
	// 2.from max_idx+1 to end
    // from max_idx to end the left maximum is constant
	l=height[max_idx];
	r=height[heightSize-1];
	for(int i=heightSize-1; i>max_idx; i--){
		if(r<height[i]){
			r=height[i];
		}
		units+=Min(l,r)-height[i];
	}
	
	return units;
	
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends