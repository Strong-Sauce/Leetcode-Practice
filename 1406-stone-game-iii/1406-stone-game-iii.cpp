class Solution {
public:
    vector<int> dp;
    int n;

    int solve(int i, vector<int>& stone) {

        if (i >= n)
            return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int take = 0;
        int best = INT_MIN;

        for (int k = 0; k < 3 && i + k < n; k++) {
            take += stone[i + k];
            best = max(best, take - solve(i + k + 1, stone));
        }

        return dp[i] = best;
    }

    string stoneGameIII(vector<int>& stoneValue) {

        n = stoneValue.size();
        dp.assign(n, INT_MIN);

        int diff = solve(0, stoneValue);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};