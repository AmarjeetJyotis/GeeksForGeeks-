// User function Template for C++
class Solution {
  public:
  
  void reverse(string &s, int i, int j){
      if(i>=j){
          return ;
      }
      swap(s[i], s[j]);
      
      reverse(s, i+1, j-1);
  }
    string reverseString(string& s) {
        // code here
        int i=0;
        int j=s.length()-1;
        reverse(s, i, j);
        return s;
    }
};
