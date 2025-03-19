//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends





class Solution
{
    public:
    // Function to find all possible unique subsets.
    vector<vector<int>> AllSubsets(vector<int> arr, int n)
    {
        // Sort the array to handle duplicates and generate subsets in lexicographical order
        sort(arr.begin(), arr.end());

        vector<vector<int>> result; // To store all unique subsets
        vector<int> subset; // Temporary subset to store the current subset being generated

        // Start generating subsets using backtracking
        backtrack(arr, n, 0, subset, result);

        return result;
    }

    private:
    void backtrack(vector<int>& arr, int n, int index, vector<int>& subset, vector<vector<int>>& result)
    {
        // Add the current subset to the result
        result.push_back(subset);

        for (int i = index; i < n; i++) {
            // Skip duplicates to avoid duplicate subsets
            if (i > index && arr[i] == arr[i - 1]) continue;

            // Include the current element in the subset
            subset.push_back(arr[i]);

            // Recur to generate subsets that include the current element
            backtrack(arr, n, i + 1, subset, result);

            // Backtrack and remove the current element from the subset
            subset.pop_back();
        }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    
cout << "~" << "\n";
}
}   



// } Driver Code Ends