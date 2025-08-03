class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int maxi=INT_MIN;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>maxi){
                maxi=arr[i];
            }
        }
        int ans=-1;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > ans && arr[i] !=maxi){
                ans=arr[i];
            }
        }
        return ans;
    }
};