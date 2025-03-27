//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends


//User function Template for C++
typedef  pair<int,int> pii;
class Solution{
    public:
    vector<int> Kclosest(vector<int>arr, int n, int x, int k) 
    { 
        priority_queue<pii,vector<pii>,greater<pii> >pq;
      for(int i=0;i<n;i++){
          pq.push({abs(x-arr[i]),arr[i]});
      }
      vector<int>ka;
      for(int i=0;i<k;i++){
          ka.push_back(pq.top().second);
          pq.pop();
      }
      sort(ka.begin(),ka.end());
  return ka;  }  
};


//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,k;
		cin>>n>>x>>k; 
		vector <int> array(n);
		for (int i = 0; i < n; ++i)
			cin>>array[i];
        
        Solution obj;
		vector <int> result = obj.Kclosest(array, n, x, k); 
		for (int i = 0; i < result.size(); ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	
cout << "~" << "\n";
}

	return 0; 
} 




// } Driver Code Ends