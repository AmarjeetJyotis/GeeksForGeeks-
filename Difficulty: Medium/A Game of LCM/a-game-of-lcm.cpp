//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function Template for C++
static int arr[1000]= {0};
static int my_count = 0;
// 在类外初始化静态成员变量（C++11及之后的标准）
class Solution {
  public:
    // Function to calculate the least common multiple (lcm) of four numbers.
    int lcm(int a,int b,int c,int d)
    {
        // Initializing the answer with the first number.
        int ans = a;

        // Calculating lcm using gcd of the numbers.
        ans = (ans*b)/(__gcd(ans,b));
        ans = (ans*c)/(__gcd(ans,c));
        ans = (ans*d)/(__gcd(ans,d));

        // Returning the lcm.
        return ans;
    }
  
    // Function to calculate the maximum gcd given a number n.
    long long maxGcd(int n) {
        
        arr[my_count] = n;
        my_count++;
        if(my_count==50){
             std::string str = "";
             for(int i = 0 ; i < my_count ; i++){
                str += std::to_string(arr[i]);
                str += ",";
             }
            std::cout<<str<<std::endl;
            return NULL;
            // Initializing the answer.
        }
          
        int ans = 0;

        // Nested loops to calculate the maximum gcd.
        for(int i = n ; i >= 1 ; i--)
        {
            for(int j = n ; j >= 1 ; j--)
            {
                for(int k = n ; k >= 1 ; k--)
                {
                    for(int p = n ; p >= 1 ; p--)
                    {
                        // Updating the maximum gcd.
                        ans = max(ans,(int)lcm(i,j,k,p));
                    }   
                }
            }
        }

        // Returning the maximum gcd.
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends