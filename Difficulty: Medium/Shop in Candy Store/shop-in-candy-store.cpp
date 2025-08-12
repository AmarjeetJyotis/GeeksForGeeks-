class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(), prices.end()); // sort ascending
        int n = prices.size();

        // Minimum cost
        int minSum = 0;
        int i = 0, j = n - 1;
        while (i <= j) {
            minSum += prices[i]; // buy cheapest
            i++;                 // move to next cheap
            j -= k;              // take k most expensive for free
        }

        // Maximum cost
        int maxSum = 0;
        i = 0; j = n - 1;
        while (i <= j) {
            maxSum += prices[j]; // buy most expensive
            j--;                 // move to next expensive
            i += k;              // take k cheapest for free
        }

        return {minSum, maxSum};
    }
};