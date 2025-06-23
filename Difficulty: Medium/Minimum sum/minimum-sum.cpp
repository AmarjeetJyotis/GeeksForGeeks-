class Solution {
  public:
    string minSum(vector<int> &arr) {
        int n = arr.size();
        
        // add a zero to make the odd array even sized;
        if (n&1) {
            arr.push_back(0);
            n = n+1;
        }
        
        sort(arr.begin(), arr.end());
        
        string ans = "";
        int carry = 0;
        
        for(int i=n-1; i>=1; i-=2) {
            int a = arr[i];
            int b = arr[i-1];
            
            if (a == 0 && b == 0 && carry == 0) break;
             
            int sum = a + b + carry;
            ans += to_string(sum%10);
            carry = sum / 10;
        }
        
        if (carry != 0) {
            ans += to_string(carry);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
