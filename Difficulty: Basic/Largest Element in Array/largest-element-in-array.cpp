class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int maxElement=INT_MIN;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>maxElement){
                maxElement=arr[i];
            }
        }
        return maxElement;
    }
};
