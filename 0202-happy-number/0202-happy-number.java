class Solution {
    long sqr(long n){
        long result = 0;
        while(n > 0){
            long rem = n % 10;
            result += (rem)*(rem);
            n /= 10;
        }
        return result;
    }
    public boolean isHappy(int n) {
        long slow = n, fast = n;

        do {
            slow = sqr(slow);
            fast = sqr(sqr(fast));
        } while(slow != fast);

        return fast == 1;
    }
}