//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends




//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    sort(a,a+n,greater<int>());
    
    int cf = 0;
    int x = 0, y = n-1;
    vector<int> ans(n);
    
    for(int i=0;i<n;i++){
        if(i%2==0) ans[i] = a[x++];
        else       ans[i] = a[y--];
    }
    
    for(int i=0;i<n;i++){
        if(i%2==0) cf += ans[i];
        else       cf -= ans[i];
        if(cf <= 0) return {-1};
    }
    return ans;
}
