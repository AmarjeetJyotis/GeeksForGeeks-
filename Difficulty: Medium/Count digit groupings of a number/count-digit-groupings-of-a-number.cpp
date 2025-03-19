//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	// function
	int count_substrings(int indx,int prev_sum,string &str,int size,vector<vector<int>> &dp){
	    // base case
	    if(indx==size){
	        // return 1
	        return 1;
	    }
	    
	    // if the dp[indx][prev_sum] is not -1
	    if(dp[indx][prev_sum]!=-1){
	        // return dp[indx][prev_sum]
	        return dp[indx][prev_sum];
	    }
	    
	    // create the variable count and sum
	    int count=0;
	    int sum=0;
	    
	    // run a loop from indx till the end of the string
	    for(int i=indx;i<size;i++){
	        // update the value of sum
	        sum+=(str[i]-'0');
	        
	        // if the prev_sum is not -1 and the sum is more than prev_sum
	        if(prev_sum!=0 && sum<prev_sum-1){
	            // break the loop 
	            continue;
	        }
	        
	        // update the value of count
	        count+=(count_substrings(i+1,sum+1,str,size,dp));
	    }
	    
	    // return count
	    return dp[indx][prev_sum]=count;
	}
	
	int TotalCount(string str){
	    // find the size of the string 
	    int size=str.size();
	    
	    // create the vector dp
	    vector<vector<int>> dp(size,vector<int>(902,-1));
	    
	    // return the function call
	    return count_substrings(0,0,str,size,dp);
	}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends