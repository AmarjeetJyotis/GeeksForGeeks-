//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//User function Template for C++

class Solution {
  public:
    int makeProductOne(int arr[], int N) 
    {
        int count_zero = 0;
        int steps = 0;
        int mul = 1;
        
        for(int i = 0; i<N; i++)
        {
            if(arr[i] > 0)
            {
                steps = steps + (arr[i] - 1);
            }
            else if(arr[i] < 0)
            {
                steps = steps + (-arr[i] - 1);
                mul = mul * -1;
            }
            else
            {
                count_zero++;
                steps = steps + 1;
            }
        }
        
        if(count_zero > 0 || mul == 1)
        {
            return steps;
        }
        else
        {
            steps = steps + 2;
        }
        return steps;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.makeProductOne(arr,N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends