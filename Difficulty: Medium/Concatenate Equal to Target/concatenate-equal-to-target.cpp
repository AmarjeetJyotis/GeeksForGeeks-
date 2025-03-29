//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i]<< " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


class Solution {
public:
    int countPairs(int N, vector<string> &nums, string target) {
        unordered_map<string, int> freq; // Hash map for frequency count
        int count = 0;

        // Step 1: Count occurrences of each number
        for (const string &num : nums) {
            freq[num]++;
        }

        // Step 2: Check for valid pairs
        for (const string &num : nums) {
            int len = num.length();
            
            // If 'num' is a valid prefix, check for the required suffix
            if (target.substr(0, len) == num) {
                string suffix = target.substr(len);
                
                // Check if suffix exists in map
                if (freq.find(suffix) != freq.end()) {
                    count += freq[suffix];

                    // Avoid counting (i, i) pairs
                    if (suffix == num) {
                        count--;
                    }
                }
            }
        }
        return count;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<string> nums;
        for(int i=0;i<N;i++){
            string temp;
            cin>>temp;
            nums.push_back(temp);
        }
        string target;
        cin>>target;
        
        Solution obj;
        int res = obj.countPairs(N, nums, target);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends