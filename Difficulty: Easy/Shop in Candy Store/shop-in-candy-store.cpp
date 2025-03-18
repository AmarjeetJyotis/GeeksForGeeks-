//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
       sort(candies, candies + N);  // Sort in ascending order
    
        int minCost = 0, maxCost = 0;
        
        // Calculate Min Cost
        int i = 0, j = N - 1;  // j is used to track free candies
        while (i <= j) {
            minCost += candies[i];  // Buy the cheapest candy
            j -= K;  // Get K candies for free from the most expensive side
            i++;
        }
        
        // Calculate Max Cost
        i = 0, j = N - 1;  // Reset pointers
        while (i <= j) {
            maxCost += candies[j];  // Buy the most expensive candy
            i += K;  // Get K candies for free from the cheapest side
            j--;
        }
    
        return {minCost, maxCost}; // Write Your Code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends