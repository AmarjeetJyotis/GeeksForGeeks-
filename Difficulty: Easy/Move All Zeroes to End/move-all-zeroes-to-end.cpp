class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        vector<int> temp;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]!=0){
                temp.push_back(arr[i]);
            }
        }
        int nz=temp.size();
        for(int i=0; i<nz; i++){
            arr[i]=temp[i];
        }
        
        // for zero
        for(int  i=nz; i<arr.size(); i++){
            arr[i]=0;
        }
    }
};