class Solution {
    public boolean uniformArray(int[] nums1) {
        int mini = Integer.MAX_VALUE;
        for(int i : nums1) mini = Math.min(mini, i);

        if(mini % 2 == 1) return true;

        for(int i : nums1){
            if(i % 2 == 1) return false;
        }

        return true;
    }
}