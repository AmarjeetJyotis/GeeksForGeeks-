/*Complete the function given below*/
class Solution {
  public:
    int num(int k, vector<int>& arr) {
        // Code here
        int count=0;
        for(int i=0; i<arr.size(); i++){
            int temp=arr[i];
            while(temp != 0){
                if(temp%10==k){
                    count++;
                }
                temp/=10;
            }
        }
        return count;
    }
};