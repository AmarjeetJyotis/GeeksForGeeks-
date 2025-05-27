class Solution {
  public:
    vector<int>ans;
    void f(int s,int e,vector<int>&nums){
        if(s==e){
            ans.push_back(nums[s]);
            return;
        }
        if(s>e){
            return ;
        }
        int k=s;

// analyze the test case and u will find that preorder has first element as root and find // the index till which we have it on left and which are on the right of it
        for(;k<=e;k++){
            if(nums[s]<nums[k]){  
                break;
            }
        }
        f(s+1,k-1,nums);
        f(k,e,nums);
    }
    vector<int> leafNodes(vector<int>& preorder) {
        f(0,preorder.size()-1,preorder);
        return ans;
        
    }
};