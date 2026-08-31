// class Solution {
//     // return the total number of comb/ways for t and i,
//     int sol(vector<int>& coins, vector<vector<int>>& dp, int t, int i){
//         if(i < 0 || t < 0) return 0;
//         if(t == 0) return 1;
        
//         if(dp[t][i] != -1) return dp[t][i];

//         int incl = sol(coins, dp, t-coins[i], i);
//         int excl = sol(coins, dp, t, i-1);

//         int result = incl + excl;
//         return dp[t][i] = result;
//     }
// public:
//     int change(int amount, vector<int>& coins) {
//         sort(coins.begin(), coins.end());
//         vector<vector<int>> dp(amount+1, vector<int>(coins.size(), -1));
//         int ans = sol(coins, dp, amount, coins.size()-1);
//         return ans;
//     }
// };

// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<uint32_t>> dp(amount + 1, vector<uint32_t>(n + 1, 0));
//         // Amount 0 has exactly one way: 
//         // choose nothing
//         // amount 0  means target is the same coin that is chosen as in dp below
//         for(int j = 0; j <= n; j++){
//             dp[0][j] = 1;
//         }

//         for(int i = 1; i <= amount; i++){
//             for(int j = 1; j <= n; j++){
//                 // Choice 1: don't use current coin
//                 dp[i][j] = dp[i][j-1];
//                 // Choice 2: use current coin
//                 if(i >= coins[j-1]){
//                     dp[i][j] += dp[i - coins[j-1]][j];
//                 }
//             }
//         }

//         return dp[amount][n];
//     }
// };

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<uint32_t> dp(amount+1,0);
        dp[0] = 1;
        
        for(int coin : coins){
            for(int i=coin;i<=amount;i++){
               dp[i] += dp[i-coin];
            }
        }

        return dp[amount];
    }
};