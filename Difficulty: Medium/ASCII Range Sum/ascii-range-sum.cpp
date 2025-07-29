class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        int n = s.size();
        vector<int> pre;
        int temp = 0;
        for(int i = 0; i < n; i++) {
            temp += s[i];
            pre.push_back(temp);
        }
        unordered_map<char, int> mp;    //index mapping
        vector<int> arr(26);
        for(int i = 0; i < n; i++) {
            if(mp.find(s[i]) != mp.end()) {
                int index = s[i] - 'a';
                int firstOccurence = mp[s[i]];
                int temp = pre[i - 1] - pre[firstOccurence];
                arr[index] = temp;
            } else {
                mp[s[i]] = i;
            }
        }
        vector<int> ans;
        for(auto i : arr) {
            if(i != 0)
            ans.push_back(i);
        }
        return ans;
    }
};

