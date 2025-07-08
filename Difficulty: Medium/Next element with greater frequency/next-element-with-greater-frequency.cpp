class Solution {
  public:
     vector<int> findGreater(vector<int>& arr) {

        unordered_map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
        }
        vector<int>tempans(arr.size(),-1);
        stack<int>st;
        st.push(arr[tempans.size()-1]);
        for(int i=arr.size()-2;i>=0;i--){
            if(mp[arr[i]]<mp[st.top()]){
                tempans[i]=st.top();
                st.push(arr[i]);
            }
            else{
                while(!st.empty()&&mp[st.top()]<=mp[arr[i]]){
                    st.pop();
                }
                if(st.empty()){
                    tempans[i]=-1; 
                st.push(arr[i]);
                }
                else{
                     tempans[i]=st.top();
                st.push(arr[i]);
                }
            }
        }
        
      return tempans;
    }

};
