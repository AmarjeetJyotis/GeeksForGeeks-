//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution{

public:

bool spi(string s){

    for(int i=0;i<s.length();i++){

        if(s[i]!=s[s.length()-1-i]){

            return false; 

        }

    }

    return true; 

}

    bool makePalindrome(int n,vector<string> &arr){

        set<string>s; 

        for(int i=0;i<n;i++){

           if(arr[i].length()>0){

            string x=arr[i]; 

            reverse(x.begin(),x.end()); 

            if(s.find(x)!=s.end()){

                s.erase(x); 

            }

            else {

                s.insert(arr[i]); 

            }

           }

        }

      // cout<<s.size();

        

     if(s.size()==1){ 

         for(auto i:s){

            if(spi(i)==false){

              

                return false; 

            }

            else {

                s.erase(i); 

            }

        }

     }

     if(s.size()!=0){

        return 0;

     }

        return true; 

        

    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends