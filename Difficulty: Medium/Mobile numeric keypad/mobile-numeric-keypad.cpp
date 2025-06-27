class Solution {
    
  public:
  vector<vector<int>> dp;

    Solution() {
        dp = vector<vector<int>>(10, vector<int>(16, -1));
    }
  int solve(int root,unordered_map<int,vector<int>>hash,string &help,int n){
      if(help.length()>=n){
          return 1;
      }
      if(dp[root][help.length()]!=-1)return dp[root][help.length()];
      int ans=0;
      for(auto it:hash[root]){
          char c=it+'0';
          help.push_back(c);
          ans+=solve(it,hash,help,n);
          help.pop_back();
      }
      return dp[root][help.length()]=ans;
  }
    int getCount(int n) {
        // code here
        unordered_map<int,vector<int>>hash;
        hash[0]={0,8};
        hash[1]={1,2,4};
        hash[2]={1,2,3,5};
        hash[3]={2,3,6};
        hash[4]={1,4,5,7};
        hash[5]={2,4,5,6,8};
        hash[6]={6,5,3,9};
        hash[7]={7,8,4};
        hash[8]={7,5,8,9,0};
        hash[9]={9,8,6};
        string help="";
        int ans=0;
        for(int i=0;i<=9;i++){
            int x=solve(i,hash,help,n-1);
            ans+=x;
        }
        return ans;
    }
};

