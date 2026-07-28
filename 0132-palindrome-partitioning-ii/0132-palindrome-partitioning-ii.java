class Solution {
    int[] memo;
    boolean isPal(String s, int l, int r){
        while(l < r){
            if(s.charAt(l) != s.charAt(r)) return false;
            l++; r--;
        }
        return true;
    }
    int dp(String s, int i){
        if(i == s.length()) return -1;

        if(memo[i] != -1) return memo[i];

        int ans = Integer.MAX_VALUE;
        for(int j=i; j<s.length(); j++){
            if(isPal(s, i, j)) ans = Math.min(ans, 1 + dp(s, j+1));
        }

        return memo[i] = ans;
    }
    public int minCut(String s) {
        memo = new int[s.length()];
        Arrays.fill(memo, -1);
        return dp(s, 0);
    }
}