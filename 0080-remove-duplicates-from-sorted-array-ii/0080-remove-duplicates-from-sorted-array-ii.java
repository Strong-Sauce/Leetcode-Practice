class Solution {
    public int removeDuplicates(int[] nums) {
        int idx=0;
        for(int i:nums){
            if(idx<2 || nums[idx-2]!=i){
                nums[idx]=i;
                idx++;
            }
        }
        return idx;
    }
}