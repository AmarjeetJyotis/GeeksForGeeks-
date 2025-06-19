class Solution {
  public:
    string caseSort(string& s) {
        int n=s.size();
        string big="";
        string small="";
        for(int i=0;i<n;i++){
            if(s[i]<='Z'){
                big+=s[i];
            }
            else{
                small+=s[i];
            }
        }
        sort(big.begin(),big.end());
        sort(small.begin(),small.end());
        for(int i=0,j=0,k=0;i<n;i++){
            if(s[i]<='Z'){
                s[i]=big[j];
                j++;
            }
            else{
                s[i]=small[k];
                k++;
            }
        }
        return s;
    }
};
