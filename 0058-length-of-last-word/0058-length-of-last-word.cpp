class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i=n-1;
        while(s[i] == ' ') i--;
        int ans = 0;
        for(i; i>=0; i--){
            if(s[i] == ' ') break;
            ans++;
        }
        return ans;
    }
};