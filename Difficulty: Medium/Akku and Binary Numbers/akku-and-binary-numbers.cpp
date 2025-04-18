//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends





class Solution {
public:
   vector<long long> numbersWith3SetBits;

    void precompute() {
        // Generate all numbers with exactly 3 set bits up to 10^12
        for (int i = 0; i < 40; i++) {
            for (int j = i + 1; j < 40; j++) {
                for (int k = j + 1; k < 40; k++) {
                    long long num = (1LL << i) | (1LL << j) | (1LL << k);
                    if (num <= 1e12) {
                        numbersWith3SetBits.push_back(num);
                    }
                }
            }
        }
        // Sort the generated numbers
        std::sort(numbersWith3SetBits.begin(), numbersWith3SetBits.end());
    }

    long long solve(long long l, long long r) {
        return upper_bound(numbersWith3SetBits.begin(), numbersWith3SetBits.end(), r) - 
               lower_bound(numbersWith3SetBits.begin(), numbersWith3SetBits.end(), l);
    }
};


 






//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends