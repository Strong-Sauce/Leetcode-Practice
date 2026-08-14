class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxi = 0, l = 0;
        vector<int> mp(26, 0);
        for(int r = 0; r < s.size(); r++) {
            int idx = s[r] - 'a';
            mp[idx]++;
            while(mp[idx] > 2) {
                mp[s[l] - 'a']--;
                l++;
            }
            maxi = max(maxi, r - l + 1);
        }
        return maxi;
    }
};