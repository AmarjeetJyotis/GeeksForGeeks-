//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
 
	public:
	int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat)
	{
		// Your code goes here
		if(mat[r][c]=='#') return 0;
		queue<pair<pair<int,int>,pair<int,int>>>pq;
		pq.push({{r,c},{u,d}});
		int ans=0;
		bool mark[n][m]={false};
		
		mat[r][c]='1';
		while(!pq.empty())
		{
		    int i=pq.front().first.first;
		    int j=pq.front().first.second;
		    int up=pq.front().second.first;
		    int down=pq.front().second.second;
		
		    pq.pop();
		    
		  mat[i][j]='1';
		   
		    mark[i][j]=true;
		     if((j-1)>=0&&mat[i][j-1]=='.')
		   {
		         pq.push({{i,j-1},{up,down}});
		          mat[i][j-1]='1';
		   }
		    if((j+1)<m&&mat[i][j+1]=='.')
		   {
		         pq.push({{i,j+1},{up,down}});
		          mat[i][j+1]='1';
		   }
		   if((i-1)>=0&&mat[i-1][j]=='.'&&(up-1)>=0)
		   {
		       pq.push({{i-1,j},{up-1,down}});
		       mat[i-1][j]='1';
		   }
		   if((i+1)<n&&mat[i+1][j]=='.'&&(down-1)>=0)
		   {
		       		       pq.push({{i+1,j},{up,down-1}});
 mat[i+1][j]='1';
		   }
		  
		}
	
		for(int i=0;i<n;i++)
		{
		    for(int j=0;j<m;j++)
		    {
		        if(mat[i][j]=='1') ans++;
		    }
		}
		return ans;
	}

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;

    while (t--)
    {
    	int n, m, r, c, u, d;
        cin >> n >> m >> r >> c >> u >> d;
        
        vector<vector<char>> mat(n, vector<char>(m, '.'));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		cin >> mat[i][j];
        	}
        }

      

        Solution obj;
        cout << obj.numberOfCells(n, m, r, c, u, d, mat) << "\n";
    
    
cout << "~" << "\n";
}

    return 0;
}



// } Driver Code Ends