//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
int MaxGold(vector<vector<int>>&m){
    // Code here
    int maxi=0;
    for(int i=0;i<m[0].size();++i) maxi=max(maxi,m[0][i]);
    for(int i=1;i<m.size();++i){
        bool c=false;
        for(int j=0;j<m[0].size();++j){
            maxi=max(maxi,m[i][j]);
            if(m[i][j]==-1) continue;
            else{
                int t=-1;
                if(j>0) t=max(t,m[i-1][j-1]);
                t=max(t,m[i-1][j]);
                if(j<m[0].size()-1) t=max(t,m[i-1][j+1]);
                m[i][j]+=t;
                if(t!=-1) c=true;
                maxi=max(maxi,m[i][j]);
            }
        }
        if(!c) return maxi;
    }
    return maxi;
}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends