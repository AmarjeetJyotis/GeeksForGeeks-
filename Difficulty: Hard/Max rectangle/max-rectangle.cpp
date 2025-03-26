//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/*You are required to complete this method*/
class Solution {
  public:
  int n, m;
    // Function to calculate the maximum area of a rectangle
    // in the given matrix.
    
    vector<int> NSE(vector<int> arr)
    {
        int n = arr.size();
        vector<int> val(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--)
        {
            while( !st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            val[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return val;
    }
    
    vector<int> PSE(vector<int> arr)
    {
        int n = arr.size();
        vector<int> val(n);
        stack<int> st;
        for(int i = 0;i<n;i++)
        {
            while( !st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            val[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return val;
    }
    
    int rectangleArea(vector<int> arr)
    {
        int n = arr.size();
        vector<int> nse , pse;
        nse = NSE(arr);
        pse = PSE(arr);
        
        int maxVal = 0;
        for(int i = 0;i<n;i++)
        {
            maxVal = max(maxVal ,  arr[i] * (nse[i] - pse[i]-1) );
        }
        
        return maxVal;
    }
    
    int maxArea(vector<vector<int>> &mat) {
        // Your code here
        
        n = mat.size();
        m = mat[0].size();
        int maxArea = 0;
        vector<int> height(m, 0);
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if( mat[i][j] == 1) height[j]++;
                else    height[j] = 0;
            }
            
            int area = rectangleArea(height);
            maxArea = max( area, maxArea);
        }
        
        return maxArea;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(mat) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends