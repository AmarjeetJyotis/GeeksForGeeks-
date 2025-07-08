// User function Template for C++

class Solution {
  public:
    pair<int, int> get(int a, int b) {
        // complete the function here
        int temp;
        temp=a;
        a=b;
        b=temp;
        return {a, b};
    }
};