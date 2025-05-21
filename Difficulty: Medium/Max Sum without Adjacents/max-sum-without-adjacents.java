// User function Template for Java

class Solution {
   int findMaxSum(int arr[], int n) {
        // code here
        int prev = arr[0];
        int prev2 = 0;

        for(int i = 1; i<n; i++){
            int take = arr[i];
            if(i>1)
            take+=prev2;
            int nTake = prev;

            int curr = Math.max(take, nTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
}