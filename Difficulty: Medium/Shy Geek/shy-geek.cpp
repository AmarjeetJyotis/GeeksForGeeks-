//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

class Shop
{
    vector<int> chocolates;
    int countOfCalls;
    public:
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50)return -1;
        return chocolates[i];
    }
};


// } Driver Code Ends


//User function Template for Java

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/
#define ll long long
class Solution{
    public:
    
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    // Helper function to get the value at position q
    ll help(int q, map<int,ll> &m, Shop &sp)
    {
        // If value already calculated, return it
        if(m.find(q)!=m.end())
            return m[q];
            
        // Calculate and store the value at position q
        return m[q] = sp.get(q-1);        
    }
    
    // Main function to find the answer
    long long find(int n, long long k) {
        // Create a map to store previously calculated values
        map<int,ll> m;
        
        // Initialize the answer to 0
        long long ans = 0;
        
        // Find the quotient and remainder when k is divided by help(n,m,this->shop)
        ans += k/help(n,m,this->shop);
        k %= help(n,m,this->shop);
        
        // Initialize the left and right indices for binary search
        int l = 0,r = n;

        // Iterate until l is equal to 0
        while(1)
        {
            // Reset l to 0
            l = 0;

            // Perform binary search to find the largest value of l
            while(l+1<r)
            {
                // Calculate the middle index
                int mid = (l+r)/2;

                // If help(mid,m,this->shop) is less than or equal to k, update l
                if(help(mid,m,this->shop)<=k)
                    l = mid;

                // Otherwise, update r
                else 
                    r = mid;
            }

            // If l is equal to 0, break the loop
            if(l==0)
                break;

            // Update the answer and k
            ans += k/help(l,m,this->shop);
            k %= help(l,m,this->shop);
        }

        // Return the final answer
        return ans;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        long long k;
        cin >> k;
        
        Shop shop;
        for(int i = 0; i<n; i++)
        {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }
        
        Solution obj(shop);
        long long res = obj.find(n, k);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends