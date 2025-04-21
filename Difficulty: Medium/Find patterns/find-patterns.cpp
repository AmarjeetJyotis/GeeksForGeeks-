//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        // code here
        int ans=0;
        int a=S.size();
        int b=W.size();
        if(b>a)
        {
            return 0;
        }
        else if(b==1)
        {
            for(int i=0;i<a;i++)
            {
                if(S[i]==W[0])
                {
                    ans++;
                }
            }
        }
        else
        {
        for(int j=0;j<a;j++)
        {
            int k=0;
            if(S[j]==W[k])
            {
                k++;
                for(int i=j+1;i<a;i++)
                {
                    if(S[i]==W[k])
                    {
                        S[i]='#';
                        k++;
                        if(k==b)
                        {
                            ans++;
                            break;
                        }
                    }
                }
                
            }
        }
        }
        return ans;


    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 


// } Driver Code Ends