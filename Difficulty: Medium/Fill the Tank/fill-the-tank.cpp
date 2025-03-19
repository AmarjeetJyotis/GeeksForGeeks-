//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


long long MAX = 1e18; //maximum value for long long integer

class Solution{
public:    
    bool check(int N,int S,long long water,int *Cap,vector<int> *graph){
        queue<pair<int,long long>> q; //create a queue to store pairs of node and water level
        vector<int> vis(100010,0); //empty vector to track visited nodes
        q.push({S,water}); //push starting node and water level to the queue
        
        //iterate while queue is not empty
        while(q.size()){
            auto val=q.front(); //get the front element of the queue
            q.pop(); //pop the front element
            int curr=val.first; //current node
            long long curr_water=val.second; //current water level
            vis[curr] = 1; //mark current node as visited
            
            if (Cap[curr-1]>curr_water) //if capacity of current node is greater than current water level, return false
                return false;
            
            curr_water-=Cap[curr-1]; //update current water level
            
            int neighbour=0; //variable to count number of unvisited neighbouring nodes
            
            for (auto it: graph[curr]){ //iterate over neighbouring nodes
                int nxt=it; //get next node
                if(!vis[nxt]) //if next node is not visited
                    neighbour+=1; //increment neighbour count  
            }
            
            if(neighbour>0) //if there are unvisited neighbouring nodes
                curr_water/=neighbour; //divide current water level among unvisited neighbours
            
            for (auto it: graph[curr]){ //iterate over neighbouring nodes again
                int nxt=it; //get next node
                if(!vis[nxt]) //if next node is not visited
                    q.push({nxt,curr_water}); //push next node and updated water level to the queue
            }
        }
        return true; //return true if all nodes are reachable with given water level
    }
    
    long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap){
        vector<int> graph[100010]; //create an array of vectors to represent the graph
        long long high=1e18,low=0; //initialize high and low variables for binary search
        
        //build the graph using the given edges
        for(int i=0;i<N-1;i++){
            graph[Edges[i][0]].push_back(Edges[i][1]); //add connected nodes to each other's adjacency list
            graph[Edges[i][1]].push_back(Edges[i][0]);
        }
        
        //perform binary search to find minimum amount of water required
        while(low<=high){
            long long mid=low+(high-low)/2; //calculate mid value
            if(mid>=MAX) return -1; //if mid value exceeds maximum value, return -1
            
            //check if it is feasible to distribute water with current mid value
            if(check(N,S,mid,Cap,graph)==false){
                low=mid+1; //if not feasible, update low value
            }
            else{
                high=mid-1; //if feasible, update high value
            }
        }
        return low; //return minimum amount of water required
    }
};

//{ Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	
cout << "~" << "\n";
}
	
	return 0;
}
// } Driver Code Ends