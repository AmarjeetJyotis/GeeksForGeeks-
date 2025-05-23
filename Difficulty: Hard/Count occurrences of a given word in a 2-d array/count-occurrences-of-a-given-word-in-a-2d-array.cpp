//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int soln(vector<vector<char>> & mat, string target, int i, int j, int k){
        int m = mat.size(), n = mat[0].size(), s = target.size();
        if(i<0 || j<0 || i>=m ||  j>=n || mat[i][j] != target[k] )
            return 0;
        if(k == s-1)
            return 1;
        int count =0;
        mat[i][j] = '\0';
        int x [] = {0,0,1,-1};
        int y [] = {1,-1,0,0};
        for(int t=0;t<4;t++){
            count+=soln(mat, target, i+x[t], j+y[t], k+1);
        }
        mat[i][j] = target[k];
        return count;
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        int ans=0;
        int m = mat.size(), n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == target[0])
                    ans+=soln(mat, target, i, j, 0);
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends