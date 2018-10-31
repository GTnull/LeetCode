class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        return solve(1, n, dp);
    }
    int solve(int left, int right, vector<vector<int>> &dp){
        if(left >= right)
            return 0;
        if(dp[left][right] != 0)
            return dp[left][right];
        int ans = INT_MAX;
        for(int i = left; i <= right; i++){
            ans = min(ans, i + max(solve(left, i - 1, dp), solve(i + 1, right, dp)));
        }
        dp[left][right] = ans;
        return ans;
    }
};
