class Solution {
    public String convert(String s, int R) {
        int n = s.length();
        if(n == 1 || R == 1) return s;
        boolean[] vis = new boolean[n];
        StringBuilder ans = new StringBuilder();

        for(int i=0; i<n && !vis[i]; i++){
            int j = R - i;
            int k = (2*j) - 2;
            int l = (2*R) - 2 - k;
            int m = i, count = 0;
            while(m < n){
                ans.append(s.charAt(m));
                vis[m] = true;
                m += count != 0 ? (l == 0 ? k : l) : (k == 0 ? l : k);
                count ^= 1;
            }
        }
        return ans.toString();
    }
}