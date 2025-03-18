//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function Template for C++

class Solution{
public:
     vector<bool> Sieve(int value) {
        vector<bool> sieve(value + 1, true);
        sieve[0] = sieve[1] = false;
        for (long long i = 2; i * i <= value; i++) {
            if (sieve[i]) {
                for (long long j = i * i; j <= value; j += i) {
                    sieve[j] = false;
                }
            }
        }
        return sieve;
    }

    vector<bool> segSieve(long long L, long long R) {
        vector<bool> sieve1 = Sieve(sqrt(R));
        vector<long long> Base_Prime;
        
        for (long long i = 2; i < sieve1.size(); i++) {
            if (sieve1[i]) {
                Base_Prime.push_back(i);
            }
        }

        vector<bool> sieve2(R - L + 1, true);
        if (L == 1) sieve2[0] = false; // Mark 1 as non-prime

        for (auto prime : Base_Prime) {
            long long first_mul = (L + prime - 1) / prime * prime;
            if (first_mul < prime * prime) first_mul = prime * prime;

            for (long long j = first_mul; j <= R; j += prime) {
                sieve2[j - L] = false;
            }
        }
        return sieve2;
    }

    long long primeProduct(long long L, long long R) {
        long long ans = 1;
        const long long MOD = 1000000007;
        vector<bool> response = segSieve(L, R);

        for (long long i = 0; i < response.size(); i++) {
            if (response[i]) {
                ans = (ans * (L + i)) % MOD; // Corrected multiplication
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends