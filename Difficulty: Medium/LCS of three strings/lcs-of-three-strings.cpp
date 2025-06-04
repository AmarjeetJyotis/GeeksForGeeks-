class Solution {
  public:
    int a, b, c;
    vector<vector<vector<int>>> dp;
    int solve(int i, int j, int k, string& s1, string& s2, string& s3){
        if(i >= a || j >= b || k >= c) return 0;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        if(s1[i] == s2[j] && s2[j] == s3[k]) {
            return dp[i][j][k] = 1 + solve(i+1, j+1, k+1, s1, s2, s3);
        }
        
        return dp[i][j][k] = max({
            solve(i+1, j, k, s1, s2, s3),
            solve(i, j+1, k, s1, s2, s3),
            solve(i, j, k+1, s1, s2, s3)
        });
    }
    
    int lcsOf3(string& s1, string& s2, string& s3) {
        a = s1.length();
        b = s2.length(), 
        c = s3.length();
        
        dp = vector<vector<vector<int>>>(a, vector<vector<int>>(b, vector<int>(c, -1)));
        
        return solve(0, 0, 0, s1, s2, s3);
    }

};
