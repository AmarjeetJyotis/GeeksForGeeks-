class Solution {
  public:
    int substrCount(string &s, int k) {
        map<char,int> mp;
        int cnt = 0;
        int l=0,r=0;
        while(r<s.length()){
            mp[s[r]]++;
            r++;
            
            while((r-l)>k){
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(mp.find(s[l]));
                }
                l++;
            }
            
            if(((r-l) == k) and (mp.size() == k-1)){
                cnt++;
            }
        }
        
        return cnt;
    }
};
