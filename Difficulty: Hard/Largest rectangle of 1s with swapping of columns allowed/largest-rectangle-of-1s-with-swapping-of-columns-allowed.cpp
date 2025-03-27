//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends


//User function template for C++
class Solution{
public:	
	// Returns area of the largest rectangle of 1's
	int maxArea(vector<bool> mat[], int r, int c) {
	   vector<int>height(c,0);
	   int overall=0;
	   for(int i=0;i<r;i++){
	       for(int j=0;j<c;j++){
	           if(mat[i][j]){
	               height[j]++;
	           }
	           else{
	               height[j]=0;
	           }
	       }
	       vector<int>freq(r+1,0);
	       int max_h=0;
	       for(int h:height){
	           if(h>max_h){
	               max_h=h;
	           }
	           freq[h]++;
	       }
	       int count=0;
	       int maxi=0;
	       for(int h=max_h;h>=1;h--){
	           count+=freq[h];
	           int area=h*count;
	           if(area>maxi){
	               maxi=area;
	           }
	       }
	 
	       if(overall<maxi){
	           overall=maxi;
	       }
	       
	       
	   }
	   return overall;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c, x;
        cin >> r >> c;
        vector<bool> mat[r];
        for (int i = 0; i < r; i++) {
            mat[i].assign(c, false);
            for (int j = 0; j < c; j++) {
                cin >> x;
                mat[i][j] = x;
            }
        }
        Solution ob;
        auto ans = ob.maxArea(mat, r, c);
        cout << ans << "\n";

    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends