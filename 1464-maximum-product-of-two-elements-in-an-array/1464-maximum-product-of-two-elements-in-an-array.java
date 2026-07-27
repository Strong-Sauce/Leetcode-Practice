class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int num = nums[0];
        int maxi = 0;
        for(int i=1; i<n; i++){
            maxi = Math.max(maxi , (nums[i]-1)*(num-1));
            num = Math.max(num , nums[i]);
        }
        return maxi;
    }
}