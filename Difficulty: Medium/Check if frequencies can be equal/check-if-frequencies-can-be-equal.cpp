class Solution {
  public:
    bool sameFreq(string& s) {
  map<char,int>mp;
    for(int i=0;i<s.size();i++){
      mp[s[i]]++;
    }
  vector<int>v;
  for(auto &it:mp){
      v.push_back(it.second);
  }
  int n=v.size();
  sort(v.begin(),v.end());
  bool flag=true;
  if(v.size()==2){
      if(v[0]!=v[1]){
          if((v[0]==1 || v[1]==1) ||(v[1]-v[0]==1) ){
              return true;
          }else{
              return false;
          }
      }
  }else{
  for(int i=1;i<n;i++){
      if(v[i]-v[i-1]!=0){
          if (((v[i] - v[i - 1]) == 1 || v[i-1]==1) && flag){
              flag=false;
              if(v[i-1]!=1){
                  v[i]=v[i]-1;
              }
          }else{
              return false;
          }
      }
  }
  }
  return true;
    }
};