//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


class Solution {
  public:
    long long dfs(int node, vector<int> graph[], vector<int> &A, int flag) {
        long long ans = -1e18;
        for(auto i : graph[node])
            ans = max(ans, dfs(i, graph, A, !flag));
            
        long long value = A[node - 1];
        if(flag)
            value = -value;
        if(ans == -1e18)
            return value;
        return value + ans;
    }
    
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        vector<int> graph[N + 1];
        for(int i = 1; i < N; i++)
            graph[P[i]].push_back(i + 1);
            
        long long ans = -1e18;
        for(int i = 1; i <= N; i++)
            ans = max(ans, dfs(i, graph, A, 0));
        return ans;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends