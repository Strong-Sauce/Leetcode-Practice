class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        pair<int, int> mini = {nums[0], 0};
        pair<int, int> maxi = {nums[0], 0};
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < mini.first) mini = {nums[i], i};
            else if(nums[i] > maxi.first) maxi = {nums[i], i};
        }
        int n = nums.size();
        int l = min(mini.second, maxi.second);
        int r = max(mini.second, maxi.second);
        int ans = min(r+1, (n-l));
        ans = min(ans, (l+1) + (n-r));

        return ans;
    }
};