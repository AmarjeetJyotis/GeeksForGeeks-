class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_map <int, int> mp;
        int i = 0, j = 0, n = arr.size();
        int ans = 0;
        
        while(j < n){
            mp[arr[j]]++;
            
            while(i < j && mp.size() > k){
                mp[arr[i]]--;
                if(mp[arr[i]] == 0) mp.erase(arr[i]);
                i++;
            }
            
            ans += (j-i+1);
            j++;
        }
        
        return ans;
    }

};