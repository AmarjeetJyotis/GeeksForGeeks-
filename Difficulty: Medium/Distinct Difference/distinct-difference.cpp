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
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
            
        set<int>leftFreq;
        int left[N]={0};
        left[0]=0;
        leftFreq.insert(A[0]);
        for (int i=1; i<N; i++){
            int element = A[i];
            left[i]=leftFreq.size();
            leftFreq.insert(element);
            
        }
        
        int right[N]={0};
        set<int>rightFreq;
        rightFreq.insert(A[N-1]);
        for (int i=N-2;i>=0; i--){
            right[i]=rightFreq.size();
            rightFreq.insert(A[i]);
        }
        
        vector<int>ans;
        for (int i=0; i<N; i++){
            int element= left[i]-right[i];
            ans.push_back(element);
        }
        return ans;
        
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends