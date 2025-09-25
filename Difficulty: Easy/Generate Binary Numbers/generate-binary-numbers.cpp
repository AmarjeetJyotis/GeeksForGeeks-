class Solution {
  public:
  
    string solve(int i) {
        
        string ans = "";
        
        while (i > 0) {
            
            ans += to_string(i % 2);
            i /= 2;
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    vector<string> generateBinary(int n) {
        // code here
        vector<string> ans;
        
        for (int i=1; i<=n; i++) {
            
            ans.push_back(solve(i));
        }
        
        return ans;
    }
};