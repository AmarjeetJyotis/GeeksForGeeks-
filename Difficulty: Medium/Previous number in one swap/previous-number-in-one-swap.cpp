//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution{   
public:
    string previousNumber(string s){
        // code here 
        int n = s.size();
        string ans;
        int i;
        bool flag = false;
        for(i=n-2; i>=0; i--){
            if(s[i]>s[i+1]){
                flag = true;
                break;
            }
        }
        if(!flag){
            ans = "-1";
            return ans;
        }
        int ind, j=n-1;
        
        for(j=n-1; j>i; j--){
            if(s[i]>s[j] && s[j]!=s[j-1]){
                break;
            }
        }
        
        swap(s[i], s[j]);
        if(s[0]=='0'){
            return "-1";
        }
        return s;
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 
// } Driver Code Ends