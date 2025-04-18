//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends






//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.

long long num_blocked(int i,int j,int N,int M)
{
   long long c=0;
   if(i+1<N && j+2<M)
      c++;
    if(i+1<N && j-2>=0)
      c++;
    if(i+2<N && j+1<M)
      c++;
    if(i+2<N && j-1>=0)
      c++;
    if(i-1>=0 && j+2<M)
      c++;
    if(i-1>=0 && j-2>=0)
      c++;
    if(i-2>=0 && j+1<M)
      c++;
    if(i-2>=0 && j-1>=0)
     c++;
    return c;
}

long long numOfWays(int N, int M)
{
    // write code here
    long long ans=0;
    long long total=N*M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            long long b=num_blocked(i,j,N,M);
            ans+=total-b-1;
        }
    }
    return (ans)%1000000007;
}