class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for(int i=0; i<t.size(); i++){
            if(idx >= s.size()) return true;
            if(s[idx] == t[i]) idx++;
        }
        if(idx < s.size()) return false;
        return true;
    }
};