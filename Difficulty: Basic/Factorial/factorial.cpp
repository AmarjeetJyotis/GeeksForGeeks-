class Solution {
  public:
    int factorial(int n) {
        // code here
        if(n<=1){
            return n;
        }
        int ans=n*factorial(n-1);
        return ans;
    }
};