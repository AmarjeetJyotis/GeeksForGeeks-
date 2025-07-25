class Solution {
public:
    long cntCoprime(vector<int>& nums) {
        int M = *max_element(nums.begin(), nums.end());
        vector<int> ctr(M + 1, 0);
        for (int el : nums) ctr[el]++;
        vector<int> mctr(M + 1, 0);
        for (int i = 1; i <= M; ++i)
            for (int mul = 1; i * mul <= M; ++mul)
                mctr[i] += ctr[i * mul];
        vector<long> dp(M + 1, 0);
        for (int i = M; i >= 1; --i) {
            dp[i] = (long)mctr[i] * (mctr[i] - 1) / 2;
            for (int mul = 2; i * mul <= M; ++mul)
                dp[i] -= dp[i * mul];
        }
        return dp[1];
    }
};
