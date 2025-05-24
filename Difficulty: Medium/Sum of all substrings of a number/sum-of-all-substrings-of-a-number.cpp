class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int n=s.size();
        vector<string>sub;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                sub.push_back(s.substr(i,j-i+1));
            }
        }
        int sum=0;
        n=sub.size();
        for(int i=0;i<n;i++)
        {
            int num=stoi(sub[i]);
            sum+=num;
        }
        return sum;
    }
};

