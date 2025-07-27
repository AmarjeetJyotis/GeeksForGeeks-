class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int s=0;
        int e=n;
        int ans=-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(mid*mid==n){
                return mid;
            }
            else if(mid*mid>n){
                e=mid-1;
            }
            else{
                ans=mid;
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};