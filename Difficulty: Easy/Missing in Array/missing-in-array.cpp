class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int sum=1;
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++){
            if(sum == arr[i]){
                sum++;
            }
        }
        return sum;
    }
};