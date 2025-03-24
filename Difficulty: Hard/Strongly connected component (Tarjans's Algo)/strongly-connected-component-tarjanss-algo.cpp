//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    void dfs(vector<int> adj[], vector <int> &ids,vector <int> &low, vector <bool> &onStack, stack <int> &stk,
    vector <vector<int>> &scs,int &time,int & node){
        
        ids[node] = low[node] = time++;
        onStack[node] = 1;
        stk.push(node);
        
        for(int i=0;i<adj[node].size();i++){
            
            int child = adj[node][i];
            if(ids[child] == -1){
                
                dfs(adj,ids,low,onStack,stk,scs,time,child);
                low[node] = min(low[node],low[child]);
            }
            else if(onStack[child])
            low[node] = min(low[node],low[child]);
        }
        
        if(ids[node] == low[node]){
            
            vector <int> conn;
            while(!stk.empty()){
                
                int child = stk.top();
                stk.pop();
                
                onStack[child] = 0;
                conn.push_back(child);
                
                low[child] = ids[node];
                if(node == child)
                break;
                
            }
            sort(conn.begin(),conn.end());
            scs.push_back(conn);
            
        }
        
    }
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        int time = 0;
        vector <int> ids(V,-1);
        vector <int> low(V,-1);
        vector <bool> onStack(V,0);
        stack <int> stk;
        vector <vector <int> > scs;
        
        for(int i=0;i<V;i++){
            if(ids[i] == -1)
            dfs(adj,ids,low,onStack,stk,scs,time,i);
        }
        
        sort(scs.begin(),scs.end());
        
        return scs;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends