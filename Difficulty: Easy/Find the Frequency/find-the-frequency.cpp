/*Function to find frequency of x
 * x : element whose frequency is to be found
 * arr : input vector
 */
class Solution {
  public:
    int findFrequency(vector<int> arr, int x) {
        // Your code here
        int cnt=0;
        map<int, int>mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
    return mp[x];
    }
};