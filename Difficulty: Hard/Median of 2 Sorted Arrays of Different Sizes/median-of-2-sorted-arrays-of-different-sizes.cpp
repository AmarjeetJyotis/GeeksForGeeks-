//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
        if(a.size()>b.size())
            return medianOf2(b,a);
            
        int te=a.size()+b.size();
        int rel=(te+1)/2;
        int st=0,en=a.size();
        
        while(st<=en)
        {
            int md1=st+(en-st)/2;
            // md1 is no of element take from array 'a'
            int md2=rel-md1;
            
            int l1,l2,r1,r2;
            
            if(md1==0)l1=INT_MIN;
            else l1=a[md1-1];
            
            if(md1==a.size())r1=INT_MAX;
            else r1=a[md1]; 
            
            if(md2==0)l2=INT_MIN;
            else l2=b[md2-1];
            
            if(md2==b.size())r2=INT_MAX;
            else r2=b[md2]; 
            
            if(l1<=r2 && l2<=r1)
            {
                if(te%2==1)return max(l1,l2);
                else
                    return (max(l1,l2)+min(r1,r2))/2.0;
            }else if(l1>r2)
                en=md1-1;
            else
                st=md1+1;
            
            
        }
        return -1;
        
        
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline after reading `t`

    while (t--) {
        // Read the first array
        string line1;
        getline(cin, line1);
        stringstream ss1(line1);

        vector<int> array1;
        int num;
        while (ss1 >> num) {
            array1.push_back(num);
        }

        // Read the second array
        string line2;
        getline(cin, line2);
        stringstream ss2(line2);

        vector<int> array2;
        while (ss2 >> num) {
            array2.push_back(num);
        }

        // Create a Solution object and calculate the median
        Solution ob;
        if (array2.size() == 1 && array2[0] == 0) {
            array2.pop_back();
        }

        double ans = ob.medianOf2(array1, array2);
        if (ans == (int)ans) {
            cout << (int)ans << endl;
        } else {
            cout << ans << endl;
        }

        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends