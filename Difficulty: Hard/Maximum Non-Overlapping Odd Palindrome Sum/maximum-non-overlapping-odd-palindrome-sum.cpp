class Solution {
  public:
    int maxSum(string &s) {
        int n=s.size(),l=0,r=-1;

        vector<int>vl(n),vr(n),vm(n);
            for(int i=0;i<n;i++){
                vm[i]=(i>r)?1:min(r-i+1,vm[l+r-i]);
                while(vm[i]+i<n&&i-vm[i]>=0&&s[vm[i]+i]==s[i-vm[i]]){
                    vm[i]++;
                    vr[i-vm[i]+1]=max(vr[i-vm[i]+1],2*vm[i]-1);
                    vl[i+vm[i]-1]=max(vl[i+vm[i]-1],2*vm[i]-1);
                }
                if(vm[i]+i>r){
                    l=i-vm[i]+1;
                    r=i+vm[i]-1;
                }
                vr[i-vm[i]+1]=max(vr[i-vm[i]+1],2*vm[i]-1);
                vl[i+vm[i]-1]=max(vl[i+vm[i]-1],2*vm[i]-1);
             }
            for(int i=1;i<n;i++){
                vl[i]=max(vl[i],vl[i-1]);
                vr[n-i-1]=max(vr[n-i],vr[n-i-1]);
            }
            int res=0;
            for(int i=0;i<n-1;i++){
                res=max(res,vl[i]+vr[i+1]);
            }
        
        return res;
    }
};
