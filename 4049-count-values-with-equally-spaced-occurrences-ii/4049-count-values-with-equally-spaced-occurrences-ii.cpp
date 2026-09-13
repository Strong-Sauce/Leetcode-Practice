class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> mp; // value , indx
        unordered_map<int, int> check; // value , current indx diff
        unordered_map<int, bool> count; // value , true/false
        
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                if(check.find(nums[i]) != check.end()){
                    if(check[nums[i]] == i - mp[nums[i]] && (count.find(nums[i]) == count.end() || count[nums[i]] != false)){
                        count[nums[i]] = true;
                    }
                    else count[nums[i]] = false;
                }
                else check[nums[i]] = i - mp[nums[i]];
            }
            mp[nums[i]] = i;
        }

        int res = 0;
        for(auto [value, ans] : count){
            if(ans) res++;
        }
        
        return res;
    }
};