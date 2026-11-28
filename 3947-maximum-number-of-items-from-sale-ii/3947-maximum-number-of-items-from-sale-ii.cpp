class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int maxFact = 0, minPrice = INT_MAX;
        for (auto& item : items) {
            maxFact = max(maxFact, item[0]);
            minPrice = min(minPrice, item[1]);
        }
        vector<int> freq(maxFact + 1, 0);
        for (auto& item : items) {
            freq[item[0]]++;
        }
        
        map<int, long long> mp;
        for (auto& item : items) {
            int price = item[1];
            int f = item[0];
            if (price > 2 * minPrice) continue;
            long long cnt = 0;
            for (int i = f; i <= maxFact; i += f) {
                cnt += freq[i];
            }
            cnt--;
            if (cnt > 0) {
                mp[price] += cnt;
            }
        }

        long long bonus = 0;
        long long cur = budget;
        for (auto& [price, cnt] : mp) {
            if (cur < price) break;
            long long buy = min(cnt, 1LL * cur / price);
            cur -= buy * price;
            bonus += buy;
        }
        long long ans = cur / minPrice;
        ans += 2 * bonus;
        return ans;
    }
};