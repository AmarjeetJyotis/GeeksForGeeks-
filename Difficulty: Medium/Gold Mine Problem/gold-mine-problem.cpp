class Solution {
    int solve(int ind, int col, int n, int m, vector<vector<int>>& dp, vector<vector<int>>& nums) {
        if (col == m - 1) return nums[ind][col];
        if (dp[ind][col] != -1) return dp[ind][col];

        int du = 0, r = 0, dd = 0;
        if (ind - 1 >= 0) du = nums[ind][col]+solve(ind - 1, col + 1, n, m, dp, nums);
        r =  nums[ind][col]+solve(ind, col + 1, n, m, dp, nums);
        if (ind + 1 < n) dd =  nums[ind][col]+solve(ind + 1, col + 1, n, m, dp, nums);

        return dp[ind][col] = max(du,max(r,dd));
    }

public:
    int maxGold(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, 0, n, m, dp, nums));
        }
        return ans;
    }
};

