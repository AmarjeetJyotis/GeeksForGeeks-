class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int maxi = *max_element(arr.begin() , arr.end());
        if(maxi <= 0) return 1;
        int n = arr.size();
        int ans =  1 , i = 1;
        vector<bool> temp(maxi, false);
        for (int it : arr) if(it > 0) temp[it] = true ;
        bool f = false;
        for(ans ; ans < maxi ; ans++) if(!temp[ans]){
            f = true ;
             break;
        }
        if(f) return ans ;
        return ans+1 ;
    }

};