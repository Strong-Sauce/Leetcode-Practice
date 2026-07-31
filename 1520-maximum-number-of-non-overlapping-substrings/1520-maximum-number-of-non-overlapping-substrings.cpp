class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> start(26, n), end(26, -1);

        // 1. Record first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            start[idx] = min(start[idx], i);
            end[idx] = max(end[idx], i);
        }

        vector<pair<int, int>> intervals;

        for (int c = 0; c < 26; ++c) {
            if (start[c] > end[c]) continue;

            int l = start[c];
            int r = end[c];
            bool changed = true;

            // Expand the window until all characters inside it
            // have all their occurrences inside as well
            while (changed) {
                changed = false;
                for (int i = l; i <= r; ++i) {
                    int ch = s[i] - 'a';
                    if (start[ch] < l) {
                        l = start[ch];
                        changed = true;
                    }
                    if (end[ch] > r) {
                        r = end[ch];
                        changed = true;
                    }
                }
            }

            // Only add if the interval starts at this character’s first occurrence
            if (l == start[c]) {
                intervals.emplace_back(l, r);
            }
        }

        // 3. Sort by end to apply greedy selection
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<string> result;
        int prevEnd = -1;
        for (auto [l, r] : intervals) {
            if (l > prevEnd) {
                result.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return result;
    }
};
