//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	static bool cmp(pair<long long ,long long > a,pair<long ,long >b)
	{
	    long double  r1,r2;
	    r1 = (long double)a.first/a.second;
	    r2 = (long double)b.first/b.second;
	    return r1>r2;
	}
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
	    vector<pair<long long,long long>>v;
	    for(int i=0;i<N;i++)
	    {
	        v.push_back({p[i],w[i]});
	    }
	    sort(v.begin(),v.end(),cmp);
	    long double ans=0;
	    
	    for(int i=0;i<v.size();i++)
	    {
	        auto temp=v[i];
	        long long  x=temp.first;
	        long long  y=temp.second;
	        long long  sno=sqrt(y);
	        if(sno*sno==y)
	        {
	            continue;
	        }
	        if(y<=C)
	        {
	           C-=y;
	            ans+=x;
	        }
	        else
	        {
	            ans+=((x/(long double)y)*(long double)C);
	            break;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends