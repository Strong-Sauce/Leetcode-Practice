class Solution {
public:
    vector<long long> resultArray(const vector<int>& nums, const int k) {
        vector<long long> dp(k), ndp(k), ret(k);
        for (auto u : nums) {
            u %= k;
            ndp[u] = 1; ++ret[u];
            for (int i = 0; i < k; i++) {
                const int v = i * u % k;
                ndp[v] += dp[i];
                ret[v] += dp[i];
            }
            swap(dp, ndp);
            fill(ndp.begin(), ndp.end(), 0);
        }
        return ret;
    }
};