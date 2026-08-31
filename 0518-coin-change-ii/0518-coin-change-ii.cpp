class Solution {
    // return the total number of comb/ways for t and i,
    int sol(vector<int>& coins, vector<vector<int>>& dp, int t, int i){
        if(i < 0 || t < 0) return 0;
        if(t == 0) return 1;
        
        if(dp[t][i] != -1) return dp[t][i];

        int incl = sol(coins, dp, t-coins[i], i);
        int excl = sol(coins, dp, t, i-1);

        int result = incl + excl;
        return dp[t][i] = result;
    }
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(amount+1, vector<int>(coins.size(), -1));
        for(int c=0; c<coins.size(); c++){
            dp[0][c] = 0;
        }
        int ans = sol(coins, dp, amount, coins.size()-1);
        return ans;
    }
};