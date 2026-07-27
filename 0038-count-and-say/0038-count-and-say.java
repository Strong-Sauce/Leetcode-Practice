class Solution {
    public String countAndSay(int n) {
        if(n==1) return "1";
        String prev = countAndSay(n-1);
        char dig = prev.charAt(0);
        StringBuilder ans = new StringBuilder();
        int count = 1;
        for(int i=1; i<prev.length(); i++){
            if(prev.charAt(i) != dig){
                ans.append(count);
                ans.append(dig);
                dig = prev.charAt(i);
                count = 1;
            }
            else{
                count++;
            }
        }
        ans.append(count);
        ans.append(dig);
        return ans.toString();
    }
}