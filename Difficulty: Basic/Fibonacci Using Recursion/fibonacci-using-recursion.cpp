class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        if(n<=1){
            return n;
        }
        int ans=nthFibonacci(n-1)+nthFibonacci(n-2);
        return ans;
    }
};