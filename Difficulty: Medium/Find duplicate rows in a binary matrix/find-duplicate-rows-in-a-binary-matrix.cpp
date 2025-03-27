//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


//User function Template for C++

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        set<vector<int>> seen;  // Set to store unique rows
    vector<int> repeatedRows;  // Stores indices of repeated rows

    for (int i = 0; i < matrix.size(); i++) {
        if (seen.find(matrix[i]) != seen.end()) {
            repeatedRows.push_back(i);  // Row is repeated, store its index
        } else {
            seen.insert(matrix[i]);  // Insert row into the set
        }
    }
    return repeatedRows;
    } 
};




//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}



// } Driver Code Ends