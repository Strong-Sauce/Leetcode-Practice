class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        // int one = climbStairs(n-1);
        // int two = climbStairs(n-2);
        // return one + two;
        vector<int> dp(n+1, 1);
        dp[2] = 1;
        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};