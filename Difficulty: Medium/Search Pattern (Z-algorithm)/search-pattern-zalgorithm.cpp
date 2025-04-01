//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
        vector<int> calc(string s){
            int n=s.size();
            vector<int>z(n,0);
            int l=0,r=0;
            int i=1;
            while(i<n){
                if(i<=r){
                    z[i]=min(z[i-l],(r-i+1));
                }
                
                while(i+z[i]<n && s[i+z[i]]==s[z[i]]){
                    z[i]++;
                }
                
                if(i+z[i]-1>r){
                    l=i;
                    r=i+z[i]-1;
                }
                i++;
            }
            return z;
        }
        vector <int> search(string pat, string txt)
        {
            string s=pat+"#"+txt;
            vector<int>z=calc(s);
            vector<int>ans;
            for(int i=0;i<z.size();i++){
                if(z[i]==(int)pat.size()){
                    ans.push_back(i-pat.size());
                }
            }
            
            if(((int)ans.size())==0) return {-1};
            return ans;
        }
     
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}


// } Driver Code Ends