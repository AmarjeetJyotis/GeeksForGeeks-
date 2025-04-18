//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        // Code here
        int n=matrix.size(),r,c;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!matrix[i][j]){
                    r=i;c=j;
                    break;
                }
            }
        }
        unordered_set<long long>s;
        for(int i=0;i<n;i++){
            long long sum1=0,sum2=0;
            for(int j=0;j<n;j++){
                if(i!=r)
                sum1+=matrix[i][j]*1LL;
                if(i!=c)
                sum2+=matrix[j][i]*1LL;
            }
            if(sum1)
            s.insert(sum1);
            if(sum2)
            s.insert(sum2);
        }
        if(s.size()>1)
        return -1;
        long long s1=0,s2=0;
        for(int i=0;i<n;i++){
            s1+=matrix[r][i]*1LL;
            s2+=matrix[i][c]*1LL;
        }
       
        long long val=*s.begin();
        if(s1!=s2||s1>=val)
        return -1;
        long long ans=(val-s1);
        long long s3=0,s4=0;
        for(int i=0;i<n;i++){
            if(r==c&&i==r)
            s3+=ans;
            else s3+=matrix[i][i]*1LL;
            if(i==r&&n-i-1==c)
            s4+=ans;
            else s4+=matrix[i][n-i-1]*1LL;
        }
        if(s3!=s4)
        return -1;
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends