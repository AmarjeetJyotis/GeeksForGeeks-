//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool find4Numbers(int A[], int n, int X);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, x;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin>>x;
        cout << find4Numbers(a, n, x) << endl;

    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends




//User function Template for C++

bool find4Numbers(int a[], int n, int x)  
{
    for(int i=0;i<n;i++)
    for(int j=0;j<n-1;j++)
    if(a[j]>a[j+1])
    swap(a[j],a[j+1]);
    
    for(int i=0;i<n-3;i++)
    {
        
        for(int j=i+1;j<n-2;j++)
        {
            int sum=x-a[i]-a[j];
            int end=n-1,start=j+1;
            while(start<end)
            {
                // cout<<a[j]+a[i]+a[start]+a[end]<<" ";
                if(sum==a[start]+a[end])
                return 1;
                else if(sum>a[start]+a[end])
                    start++;
                else    end--;
            }
        }
    }
    return 0;
}