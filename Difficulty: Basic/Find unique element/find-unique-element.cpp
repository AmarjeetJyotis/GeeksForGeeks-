class Solution {
  public:
    int findUnique(int k, vector<int>& arr) {
        // code here
        map<int, int>mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
         for(auto it : mp){
          if(it.second == 1){
              return it.first;
          }
      }
      return -1;
    }
};