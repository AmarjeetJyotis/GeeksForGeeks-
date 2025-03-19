//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
     void nullPoints(int n, double magnet[], double getAnswer[])
    {
        for(int i=0;i<n-1;i++){
        getAnswer[i]=Nuteral_point(magnet[i],magnet[i+1],magnet,n);
        }
    }
    double Nuteral_point( double low,double right,double magnet[],int n){
        while(low<right){
           
            double mid=(low+right)/2;
             double total=0;
            for(int i=0;i<n;i++){
                
                total+=1/(mid-magnet[i]);
            }
            if(abs(total)<0.000001)
                return mid;
            
            else if(total<0){
                right=mid;
            }
            else{
                low=mid;
            }
        }
       return low; 
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
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends