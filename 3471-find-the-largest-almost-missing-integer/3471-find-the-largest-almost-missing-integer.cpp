class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int freq[51] = {};
        for(int x : nums) freq[x]++;
        if(k == n) {
            for(int x = 50; x >= 0; x--) {
                if(freq[x] >= 1) return x;
            }
            return -1;
        }
        if(k == 1) {
            for(int x = 50; x >= 0; x--) {
                if(freq[x] == 1) return x;
            }
            return -1;
        }

        int ans = -1;
        if(freq[nums[0]] == 1) ans = max(ans, nums[0]);
        if(freq[nums[n-1]] == 1) ans = max(ans, nums[n-1]);

        return ans;
    }
};