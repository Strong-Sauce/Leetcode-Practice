class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        priority_queue<int> pq;
        for(int i:nums){
            pq.push(i);
        }
        int count = 1;
        int maxi = 1;
        for(int i=0; i<nums.size()-1; i++){
            int n = pq.top();
            pq.pop();
            
            if(pq.top() == n) continue;
            else if(pq.top() == n-1){
                count++;
            }
            else count = 1;
            maxi = max(maxi, count);
        }
        return maxi;
    }
};