class Solution {
  public:
     int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        
        int x=0, y=n;
        int maxi=INT_MIN;


        for(int i=0;i<left.size();i++){
            maxi=max(maxi, left[i]);
        }


        for(int i=0;i<right.size();i++){
            maxi=max(maxi, y-right[i]);
        }


        return maxi;
    }


};