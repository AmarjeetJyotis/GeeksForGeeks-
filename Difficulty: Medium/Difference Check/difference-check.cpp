class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int diff = INT_MAX;
        
        int prevHr = stoi(arr[0].substr(0,2));
        int prevMin = stoi(arr[0].substr(3,2));
        int prevSec = stoi(arr[0].substr(6,2));
        
        for(int i = 1; i < n; i++){
            int currHr = stoi(arr[i].substr(0,2));
            int currMin = stoi(arr[i].substr(3,2));
            int currSec = stoi(arr[i].substr(6,2));
            
            int timeDiff = (currHr - prevHr)*60*60 + (currMin - prevMin)*60 + (currSec-prevSec);
            
            diff = min(diff, timeDiff);
            
            prevHr = currHr;
            prevMin = currMin;
            prevSec = currSec;
        }
        
        //checking first and last;
        int firstHr = stoi(arr[0].substr(0,2));
        int firstMin = stoi(arr[0].substr(3,2));
        int firstSec = stoi(arr[0].substr(6,2));
        
        int firstTime = firstHr*60*60 + firstMin*60 + firstSec;
        int lastTime = prevHr*60*60 + prevMin*60 + prevSec;
        
        diff = min(diff, 86400 - lastTime + firstTime);
        
        return diff;
    }
};
