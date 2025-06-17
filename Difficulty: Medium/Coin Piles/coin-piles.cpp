class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size() ;
        sort(arr.begin(), arr.end()) ;
        
        int tot = accumulate(arr.begin(), arr.end(), 0) ;
        int pi=0, pre=0, remove=1e9, rsum=0 ;
        
        for(int i=0 ; i<n ; i++)
        {
            auto it = lower_bound(arr.begin(), arr.end(), arr[i]+k)-arr.begin();
            
            while(pi < it) rsum += arr[pi++] ;
            
            int left = pre, right = (tot - rsum) - (n-it)*(arr[i]+k) ;
            
            remove = min(remove, left+right) ;
            
            pre += arr[i] ;
        }
        
        return remove ;
    }
};
