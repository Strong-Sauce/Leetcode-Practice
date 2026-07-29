
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();        
        vector<int> temp(n);
        for(int i=0; i<n ;i++){
            temp[(i+k) % n]=nums[i];
        }
        int i=0;
        for(auto n:temp){
            nums[i]=n;
            i++;
        }
    }
};