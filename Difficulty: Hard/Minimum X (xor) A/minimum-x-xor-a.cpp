//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int B=b, numberOfBitsInB=0, ans=0;
        
        //count the number of bits in b;
        //numberOfBitsInB+= (B%2);
        //gives the number of bits in b
        while(B){
            numberOfBitsInB+= (B%2);
            B=B/2;
        }
        
        //set bit as same as a;
        //starting from the MSB;
        for(int i=31; i>=0 && numberOfBitsInB; i--){
            if(a & (1<<i)){
                ans = ans | (1<<i);
                numberOfBitsInB--;
            }
        }
        
        //set bits in ans starting from the lowest bit;
        //for the remaining numberOfBitsInB;
        //if numberOfBitsInB still exists;
        for(int i=0; i<32 && numberOfBitsInB; i++){
            if( (a& (1<<i)) == 0){
                ans = ans | (1<<i);
                numberOfBitsInB--;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends