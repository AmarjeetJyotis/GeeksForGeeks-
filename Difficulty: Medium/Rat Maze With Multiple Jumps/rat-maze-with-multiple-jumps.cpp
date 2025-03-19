//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    bool isSafe(vector<vector<int>>&mat,int i,int j){
        if(i < 0 || j < 0 || i >= mat.size() || j >= mat.size() || mat[i][j] == 0) return false;
        return true;
    }
    bool solve(vector<vector<int>>&mat,int i,int j,vector<vector<int>>&ans){
        if(i == mat.size()-1 && j == mat.size()-1){
            ans[i][j] = 1;
            return true;
        }
       
        
        
        if(isSafe(mat,i,j)){
            ans[i][j] = 1;
            for(int steps = 1;steps <= mat[i][j] && steps < mat.size();steps++){
             //try to go to right as much as posible
             if( solve(mat,i,j+steps,ans)){
                 
                
                 return true;

             }
             if(solve(mat,i+steps,j,ans)){
                 
                 return true;
    
             }
            
            
            }
            ans[i][j] = 0;
            return false;
        }
        return false;
       
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   int n = matrix.size();
	   
	   vector<vector<int>>ans(n,vector<int>(n,0));
	   
	   solve(matrix,0,0,ans);
	   vector<vector<int>>x;
	   x.push_back({-1});
	   return ans[n-1][n-1] == 0 ? x : ans; 
	}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends