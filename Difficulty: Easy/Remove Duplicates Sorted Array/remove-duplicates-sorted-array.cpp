class Solution {
  public:
    // Function to remove duplicates from the given array.
    vector<int> removeDuplicates(vector<int> &arr) {
        // code here
        int i=0;
        for(int j=1; j<arr.size(); j++){
            if(arr[j]!=arr[i]){
                i++;
                arr[i]=arr[j];
            }
        } 
       arr.resize(i + 1);  // Truncate the array to contain only unique elements
        return arr;
    }
};