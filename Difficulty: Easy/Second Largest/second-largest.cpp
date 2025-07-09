class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n=arr.size();
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>max)
                max=arr[i];
            
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            if(arr[i] > ans && arr[i] != max)
                ans=arr[i];
            
        }
        return ans;
        
    }
};

