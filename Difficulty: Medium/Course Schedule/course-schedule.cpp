//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<vector<int>> ar(n,vector<int>());
        vector<int> inorder(n,0);
        for(int i=0;i<m;i++){
            inorder[prerequisites[i][0]]++;
            ar[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        vector<int> ans;
        vector<bool> visit(n,0);
        for(int i=0;i<n;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();q.pop();
            if(visit[curr]){
                vector<int> a;
                return a;
            }
            visit[curr]=1;
            ans.push_back(curr);
            for(int i:ar[curr]){
                inorder[i]--;
                if(inorder[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()!=n){
            vector<int> a;
            return a;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends