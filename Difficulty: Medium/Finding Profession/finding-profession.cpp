//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function Template for C++

class Solution{
public:
char solve(int level,int pos)
{
    //Base case
    if(pos==1){
        return 'e';
    }

    if(solve(level-1,(pos+1)/2)=='e'){
        if(pos%2==0)
        return 'd';
        else
        return 'e';
    }
    else{    //parent is doctor
       if(pos%2==0)
        return 'e';
        else
        return 'd';
    }
}
    char profession(int level, int pos){
        // code here
        return solve(level,pos);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int level, pos;
        cin>>level>>pos;
        
        Solution ob;
        if(ob.profession(level, pos) == 'd')
            cout<<"Doctor\n";
        else
            cout<<"Engineer\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends