class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int s=0;
        int e=arr.size()-1;
        int i=0;
        while(i<=e){
            if(arr[i]==0){
                swap(arr[s], arr[i]);
                i++;
                s++;
            }
            else if (arr[i]==1){
                i++;
            }
            else{
                swap(arr[e], arr[i]);
                    e--;
                
            }
        }
    }
};