class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,-1);
        int min1=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {  if(arr[i]>=min1)
        {
            continue;
        }
            for(int j=i-1;j>=0;j--)
            {
                if(ans[j]==-1&&arr[i]<arr[j])
                {
                    ans[j]=i;
                }
            }
            min1=min(min1,arr[i]);
        }
        return ans;
        
    }


};