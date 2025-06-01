class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n=mat1.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                st.insert(mat1[i][j]);
            }
        }
        
        
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int d = x - mat2[i][j];
                if(st.find(d)!=st.end())
                {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};