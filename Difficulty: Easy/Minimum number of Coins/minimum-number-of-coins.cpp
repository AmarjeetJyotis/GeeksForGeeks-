//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int>currency={1,2,5,10,20,50,100,200,500,2000};
        vector<int>ans;
        sort(currency.begin(),currency.end(), greater<int>());
        int i=0;
        while(N>0){
        if(currency[i]<=N){
            ans.push_back(currency[i]);
            N=N-currency[i];
        }
        else{
            i++;
        }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends