class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n-1;
        while(l < r){
            int sum = nums[l] + nums[r];
            if(sum > target){
                r--;
                while(nums[r] == nums[r+1]) r--;
            }
            else if(sum < target){
                l++;
                while(nums[l] == nums[l-1]) l++;
            }
            else break;
        }
        vector<int> ans;
        ans.push_back(l+1);
        ans.push_back(r+1);
        return ans;
    }
};