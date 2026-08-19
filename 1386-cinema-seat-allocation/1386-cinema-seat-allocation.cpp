class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& RS) {

        unordered_map<int, int> reserved;

        for(auto &x : RS) {
            int row = x[0];
            int seat = x[1];

            reserved[row] |= (1 << seat);
        }

        int ans = 2 * (n - reserved.size());

        for(auto &[row, mask] : reserved) {

            bool left = !(mask & ((1 << 2) | (1 << 3) |
                                  (1 << 4) | (1 << 5)));

            bool right = !(mask & ((1 << 6) | (1 << 7) |
                                   (1 << 8) | (1 << 9)));

            bool middle = !(mask & ((1 << 4) | (1 << 5) |
                                    (1 << 6) | (1 << 7)));

            if(left && right)
                ans += 2;
            else if(left || right || middle)
                ans += 1;
        }

        return ans;
    }
};