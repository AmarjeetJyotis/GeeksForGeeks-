class Solution {
  public:
  bool isPalindr(string s){
      string s2 = s;
      reverse(s2.begin(),s2.end());
      return s == s2;
  }
  
  void palindr(string s,vector<string> &partition,vector<vector<string>> &ans){
      if(s.size()==0){
          ans.push_back(partition);
          return ;
      }
      for(int i = 0;i<s.size();i++){
          
          string part = s.substr(0,i+1);
          
          if(isPalindr(part)){
              partition.push_back(part);
              palindr(s.substr(i+1),partition,ans);
              partition.pop_back();
          }
      }
  }
  
  
  
    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<vector<string>> ans;
        vector<string> partition;
        palindr(s,partition,ans);
        return ans;
    }
};

