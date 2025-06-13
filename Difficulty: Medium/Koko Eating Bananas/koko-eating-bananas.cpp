class Solution {
  public:
  int calcuth(vector<int>& arr, int hour){
      int total =0 ;
      int n = arr.size();
      for(int i=0 ; i<n ; i++){
          total+=ceil(double(arr[i])/double(hour));
      }
      return total;
  }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low = 1 ; 
        int high = *max_element(arr.begin(),arr.end());
        while(low<=high){
            int mid = low+(high-low)/2;
            int totalh  = calcuth(arr,mid);
            if(totalh<=k){
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return low ;
    }
};
