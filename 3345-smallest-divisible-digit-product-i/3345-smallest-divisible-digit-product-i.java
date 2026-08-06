class Solution {
    private boolean check(int i, int t){
        int p = 1;
        while(i>0){
            p *= i%10;
            i /= 10;
        }
        if(p % t == 0) return true;
        return false;
    }
    public int smallestNumber(int n, int t) {
        if(n < t) return t;
        for(int i=n; i<=100; i++){
            if(check(i, t)) return i;
        }
        return -1;
    }
}