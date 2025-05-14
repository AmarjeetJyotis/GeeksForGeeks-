//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        // code here
        string arr="1";
        if(n==1)return "1";
        n=n-1;
        
       
      while(n--){   
        int i=0,j=0,count=0;
        string temp="";
        while(j<arr.size()){
            if(arr[i]==arr[j]){
                count++;
                j++;
            }
            else {
                temp+=to_string(count);
                temp+=arr[i];
                i=j;
                count=0;
            }
        }
        temp+=to_string(count);
        temp+=arr[i];
        i=j;
        count=0;
        arr=temp;
        temp.clear();
      }
      
      return arr;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends