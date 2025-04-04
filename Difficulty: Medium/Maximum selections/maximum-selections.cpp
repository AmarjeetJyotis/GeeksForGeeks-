//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// ranges[i][0] is the start of ith range
// ranges[i][1] is the end of ith range

class Solution{
public:
    static bool cmp(vector<int> &v1, vector<int> &v2){
        if(v1[1]!=v2[1]) return v1[1]<v2[1];
        else return v1[0]<v2[0];
    }
    int max_non_overlapping( vector< vector<int> >& ranges )
    {
        // code here
        sort(ranges.begin(), ranges.end(), cmp);
        int end = ranges[0][1];
        int count=1;
        for(int i=1; i<ranges.size(); i++){
            if(ranges[i][0]>=end){
                count++;
                end = ranges[i][1];
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		vector< vector<int> > v(n,vector<int>(2));
		for(int i=0; i<n; i++)
			cin>> v[i][0] >> v[i][1];
			
        Solution ob;
		cout<< ob.max_non_overlapping(v) << endl;
	
cout << "~" << "\n";
}
	return 1;
}


// } Driver Code Ends