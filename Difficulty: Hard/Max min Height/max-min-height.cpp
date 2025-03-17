//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++


//User function Template for C++

class Solution
{
    private:
    bool isPossible(vector<int>& a, int n, int k, int w, int target) {
        vector<int> water(n + 1, 0);
        int currentWater = 0;
        int remainingK = k;
    
        for (int i = 0; i < n; i++) {
            currentWater += water[i];
            int deficit = target - (a[i] + currentWater);
            if (deficit > 0) {
                if (remainingK < deficit) return false;
                remainingK -= deficit;
                currentWater += deficit;
                if (i + w < n) water[i + w] -= deficit;
            }
        }
        return true;
    }
    public:
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            // code here
             int low = *min_element(a.begin(), a.end());
             int high = *max_element(a.begin(), a.end()) + k;

            while (low < high) {
                int mid = (low + high + 1) / 2;
                if (isPossible(a, n, k, w, mid)) {
                    low = mid;
                } else {
                    high = mid - 1;
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
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends