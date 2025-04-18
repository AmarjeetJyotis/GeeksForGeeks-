//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<bool>prime(1e6 + 1 , true); 
        prime[0] = false;
        prime[1] = false;
        
        for(int i = 2 ; i * i < prime.size(); i++){
            if(prime[i]){
                for(int j = i * i ; j < prime.size(); j += i){
                    prime[j] = false; 
                }
            }
        }
        
        vector<int>ans(query.size());
        
        vector<pair<long long , int>>newq(query.size()); 
        for(int i = 0 ; i < query.size(); i++){
            newq[i] = {query[i] , i }; 
        }
        sort(newq.begin(), newq.end());
        
        int count = 0 ;
        int cind = 0 ; 
        
        for(auto it : newq){
            int limit = it.first;
            int ind = it.second; 
            
            for(cind ; cind < prime.size(); cind++){
                if(prime[cind]){
                    if(cind * cind <= limit){
                        count++;
                    }
                    else{
                        break; 
                    }
                }
            }
            
            ans[ind] = count;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends