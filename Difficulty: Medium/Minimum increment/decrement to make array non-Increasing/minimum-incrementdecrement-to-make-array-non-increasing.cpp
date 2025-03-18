//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends




class Solution{
public:
    int minOperations(int *a,int n)
    {
priority_queue<int,vector<int>,greater<int>>pq;//here we will get 1 1 2 3
       int steps =0;// steps in which minimum increment/decrement is stored
       for(int i =0;i<n;i++){
           if(!pq.empty()&&pq.top()<a[i]){//we will now check if pqis not empty and pq.top()<arr[i] so 
           //as the array remains non increasing
           //as we see the 3 i sbigger than we willl move forward
           //again 2 is less then3
           //then 1 comes as 1 is less than 2 therefore the 1 will be substracted from a[i]-pq.top()=1
           //hence we will now store it and move forward
           
               steps+=a[i]-pq.top();
               pq.push(a[i]);
               pq.pop();
           }
           pq.push(a[i]);//3 i spushed first
           //2 is pushed now
       }
       return steps;
    }
};

//{ Driver Code Starts.

int main() {
    
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int  a[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        Solution ob;
        cout<<ob.minOperations(a,n)<<endl;
    
cout << "~" << "\n";
}
    
	return 0;
}
// } Driver Code Ends