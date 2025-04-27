//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
        bool isNeg=false;
        if(s1[0]=='-'){
            isNeg=!isNeg;
            s1=s1.substr(1);
        }
        if(s2[0]=='-'){
            isNeg=!isNeg;
            s2=s2.substr(1);
        }
        
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        
        vector<int>res(s1.size()+s2.size(),0);
        
        for(int i=0;i<s1.size();i++){
            int num1=s1[i]-'0';
            for(int j=0;j<s2.size();j++){
                int num2=s2[j]-'0';
                
                res[i+j]+=num1*num2;
                
                if(res[i+j]>=10){
                    res[i+j+1]+=res[i+j]/10;
                    res[i+j]%=10;
                }
            }
        }
        
        string ans;
        int indx=res.size()-1;
        while(indx>0 && res[indx]==0){
            indx--;
        }
        
        if(isNeg && !(indx==0 && res[indx]==0)) ans+='-';
        
        while(indx>=0){
            ans+=(res[indx]+'0');
            indx--;
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends