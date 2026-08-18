class Solution {
public:
    string convert(string s, int R) {
        int n = s.size();
        if(n == 1 || R == 1) return s;
        vector<bool> vis(n,false);
        string ans = "";

        for(int i=0; i<n && !vis[i]; i++){
            int j = R - i;
            int k = (2*j) - 2;
            int l = (2*R) - 2 - k;
            int m = i, count = 0;
            while(m < n){
                ans += s[m];
                vis[m] = true;
                m += count ? (l == 0 ? k : l) : (k == 0 ? l : k);
                count ^= 1;
            }
        }
        return ans;
    }
};