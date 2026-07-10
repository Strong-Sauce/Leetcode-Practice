class Solution {
    private int[] memo;
    private List<String> wd;
    private String s;
    
    private boolean dp(int i){
        if(i < 0) return true;

        if(memo[i] != -1) return memo[i] == 1;

        for(String w:wd){
            int wsize = w.length();

            if(i-wsize+1 < 0)  
                continue;
            if(s.substring(i-wsize+1, i+1).equals(w) && dp(i-wsize)){
                memo[i] = 1;
                return true;
            }
        }

        memo[i] = 0;
        return false;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        this.wd = wordDict;
        this.s = s;
        this.memo = new int[s.length()];
        Arrays.fill(memo, -1);
        return dp(s.length()-1);
    }
}
