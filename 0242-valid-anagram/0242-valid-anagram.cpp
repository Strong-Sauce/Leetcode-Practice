class Solution {
public:
    bool isAnagram(string s, string t) {
        // aproch 1 tc > sc
        unordered_map<char,int> mp;
        for(char c:s) mp[c]++;
        for(char c:t) mp[c]--;
        for(auto x:mp){
            if(x.second != 0) return 0;
        }
        return 1;
        // aproch 2 sc > tc
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t) return 1;
        return 0;
        // aproch 3 best tc
        if (s.size() != t.size()) return false;
        vector<int> count(26, 0); // Assuming only lowercase letters
        for (char c : s) count[c - 'a']++;
        for (char c : t) count[c - 'a']--;
        for (int freq : count)
            if (freq != 0) return false;
        return true;
    }
};