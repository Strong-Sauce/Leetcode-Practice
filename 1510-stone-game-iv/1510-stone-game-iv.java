class Solution {
    public boolean winnerSquareGame(int n) {
        boolean[] dp = new boolean[n + 1];

        for(int i = 0; i <= n; i++) {
            if(!dp[i]) {
                for(int j = 1; i + j * j <= n; j++) {
                    dp[i + j * j] = true;
                }
                if(dp[n]) {
                    return true;
                }
            }
        }
        return false;
    }
}
// class Solution {
//     static final int MAX = 100000;
//     static final boolean[] dp = new boolean[MAX + 1];

//     static {
//         for (int i = 0; i <= MAX; i++) {
//             if (dp[i]) continue;

//             for (int j = 1; j * j <= MAX - i; j++)
//                 dp[i + j * j] = true;
//         }
//     }

//     public boolean winnerSquareGame(int n) { return dp[n]; }
// }