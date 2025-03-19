//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends


class Solution{
public:
         long posIntSol(string s)
   {
       int a = s.length(); 
       int count=0,nums=0,n;
       for(int i=0;i<s.length();i++){
           if(s[i]=='+'){
               count++;
           }
           if(s[i]=='='){
               nums = stoll(s.substr(i+1));
    
           }
       }
       count++;
   
       count = count-1;
       nums = nums-1;
       
       long long n1=1,n2=1;
       for(long long i=nums;i>nums-count;i--){
           n1*=i;
       }
           
       for(long long i=1;i<=count;i++){
           n2*=i;
       }
           
       return n1/n2;
       
   }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends