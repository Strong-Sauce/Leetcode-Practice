class Solution {
    int n, m;
    int sol(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (j == m) return 1;
        if (i == n) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int ans;

        if (s[i] == t[j]) {
            int incl = sol(s, t, i + 1, j + 1, dp);
            int excl = sol(s, t, i + 1, j, dp);
            ans = incl + excl;
        }
        else ans = sol(s, t, i + 1, j, dp);

        return dp[i][j] = ans;
    }
public:
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return sol(s, t, 0, 0, dp);
    }
};