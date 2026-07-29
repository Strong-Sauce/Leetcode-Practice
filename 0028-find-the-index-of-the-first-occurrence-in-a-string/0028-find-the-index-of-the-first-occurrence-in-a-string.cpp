class Solution {
public:
    bool check(string &haystack, string &needle, int i){
        if(haystack[i] != needle[0]) return 0;
        for(int j=1; j<needle.size(); j++){
            if(needle[j] != haystack[i+j]) return 0;
        }
        return 1;
    }
    int strStr(string haystack, string needle) {
        for(int i=0; i<haystack.size(); i++){
            if(check(haystack, needle, i)) return i;
        }
        return -1;
    }
};