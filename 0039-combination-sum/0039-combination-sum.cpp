class Solution {
public:
    vector<vector<int>> ans;
    void sol(vector<int>& can, int tar, vector<int> &temp, int i){
        if(tar == 0){
            ans.push_back(temp);
            return;
        }
        for(int j=i; j<can.size(); j++){
            if(can[j] > tar) continue;
            temp.push_back(can[j]);
            sol(can, tar-can[j], temp, j);
            temp.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
        vector<int> temp;
        sol(can, tar, temp, 0);
        return ans;
    }
};