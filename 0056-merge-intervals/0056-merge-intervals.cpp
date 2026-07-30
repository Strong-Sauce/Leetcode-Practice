class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1; i<n; i++){
            vector<int> a = ans[ans.size()-1];
            vector<int> b = intervals[i];
            
            if(a[1] >= b[0]){

                ans[ans.size()-1][1] = b[1]>a[1]?b[1]:a[1];
            }
            else{
                ans.push_back(b);
            }
        }
        return ans;
    }
};