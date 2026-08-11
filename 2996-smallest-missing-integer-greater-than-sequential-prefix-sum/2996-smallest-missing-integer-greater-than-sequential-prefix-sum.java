class Solution {
    public int missingInteger(int[] nums) {
        int idx = 0, sum = nums[0], check = sum+1, n = nums.length;
        Set<Integer> set = new HashSet<>();
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]+1){
                sum += nums[i];
                check = sum;
                idx = i;
            }
            else break;
        }
        for(int i=idx+1; i<n; i++) set.add(nums[i]);
        while(set.contains(check)) check++;
        return check;
    }
}