class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target - nums[i]) != mp.end()){
                return {mp[target - nums[i]],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         if(n < 3) return {0,1};
//         int i=0, j;
//         while(i<n-1){
//             j=i+1;
//             int dif = target - nums[i];
//             while(j<n && nums[j]!=dif) j++;
//             if(j<n) break;
//             else i++;
//         }
//         return {i,j};
//     }
// };

// chatgpt
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> mp;  // value -> index
//         for(int i = 0; i < nums.size(); i++) {
//             int complement = target - nums[i];
//             if(mp.find(complement) != mp.end()) {
//                 return {mp[complement], i};
//             }
//             mp[nums[i]] = i;
//         }
//         return {}; // This line will never be reached as per the problem's assumption
//     }
// };
