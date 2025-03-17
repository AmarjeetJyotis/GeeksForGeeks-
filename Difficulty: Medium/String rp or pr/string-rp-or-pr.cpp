//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function Template for C++
class Solution{   
public:

    long long func(string& s, string r) {
        int i,n=s.length();
        long long j = 0, sum =0;
        for(i=0;i<s.length()-1;i++) {
            if(s[i] == r[0] && s[i+1] == r[1]) {
                // cout<<i<<" "<<s<<endl;
                j=0;
                while(i>=0 && (i+1+2*j)<s.length() && s[i] == r[0] && s[i+1+2*j] == r[1]) {
                    j++;
                    i--;
                }
                s.erase(i+1, 2*j);
                sum+=j;
            }
        }
        // cout<<j<<"*"<<endl;
        return sum;
    }
    long long solve(int x,int y,string s){
      int i,j,k,n = s.length();
      long long ans = 0, temp;
      if (x > y) {
        temp = -1;
        while (ans != temp) {
            temp = ans;
            ans += (x * func(s, "pr"));
        }
        temp = -1;
        while (ans != temp) {
            temp = ans;
            ans += (y * func(s, "rp"));
        }
      } else {
        temp = -1;
        while (ans != temp) {
            temp = ans;
            ans += (y * func(s, "rp"));
        }        
        temp = -1;
        while (ans != temp) {
            temp = ans;
            ans += (x * func(s, "pr"));
        }  
    }
      return ans;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  
cout << "~" << "\n";
}
}
// } Driver Code Ends