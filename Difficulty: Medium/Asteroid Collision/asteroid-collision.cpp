//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        vector<int>ans;
        stack<int>st;
        
        for(int i=0;i<asteroids.size();i++){
            int current=asteroids[i];
            bool isDestroyed=false;
            while(!st.empty() && current<0 && st.top()>0){
                if(abs(current)>st.top()){
                    st.pop();
                }
                else if(abs(current)==st.top()){
                      isDestroyed=true;
                    st.pop();
                    break;
                }
                else{
                    isDestroyed=true;
                    break;
                }
              
            }
            
            if(!isDestroyed){
                st.push(current);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
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

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends