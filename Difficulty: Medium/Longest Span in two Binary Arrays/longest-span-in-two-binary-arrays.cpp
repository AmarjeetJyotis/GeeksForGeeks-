class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n=a1.size();
        vector<int>diff(n);
        for(int i=0;i<n;i++){
            diff[i]=a1[i]-a2[i];
        }
        unordered_map<int,int>mp;
        int CumSum=0;
        int maxlen=0;
        int len=0;
        for(int i=0;i<n;i++){
            CumSum+=diff[i];
            if(CumSum==0){
                maxlen=i+1;
            }
            if(mp.find(CumSum)!=mp.end()){
                maxlen=max(maxlen,i-mp[CumSum]);
            }
            else mp[CumSum]=i;
        }
        return maxlen;
    }
};

