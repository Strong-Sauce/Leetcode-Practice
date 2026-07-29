class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxi = 0, left=0;
        for (int right=0; right<s.size(); right++){
            if(mp.find(s[right]) != mp.end()){
                left = max(left, mp[s[right]] + 1);// dont want it to fall back in array
            }
            maxi = max(maxi, right - left +1);
            mp[s[right]] = right;
        }
        return maxi;
    }
};