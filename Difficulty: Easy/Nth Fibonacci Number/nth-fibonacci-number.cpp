// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        if(n==0 || n==1){
            return n;
        }
        else{
            return nthFibonacci(n-1)+nthFibonacci(n-2);
        }
    }
};