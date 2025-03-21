//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function template for C++

class Solution{   
public:
    bool prime(int n){

        for(int i=2;i*i<=n;i++){

            if(n%i==0)

                return 0;

        }

        return 1;

    }

    int firingEmployees(vector<int> &a, int n){

        // code here         

        vector<vector<int>>v;

        for(int i=0;i<n;i++)

            v.push_back({a[i],i+1});

        vector<int>adj[n+1];

        for(int i=0;i<v.size();i++)

            adj[v[i][0]].push_back(v[i][1]);

        queue<pair<int,int>>q;

        int st=adj[0][0];

        q.push({st,0});

        vector<int>vis(n+1,0);

        vis[st]=1;

        int ans=0;

        while(!q.empty()){

            auto f=q.front();

            q.pop();

            int node=f.first;

            int level=f.second;

            if(node!=st){

                if(prime(node+level))

                    ans++;

            }

            for(auto it:adj[node]){

                if(!vis[it]){

                    vis[it]=1;

                    q.push({it,level+1});

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
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n,0);
        
        for(int i=0; i<n; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.firingEmployees(arr, n) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends