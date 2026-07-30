class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r=matrix.size(), c=matrix[0].size();
        vector<int> ans;
        if(r==1 || c==1){ for(int b=0;b<r;b++){for(int v=0;v<c;v++){ ans.push_back(matrix[b][v]); }} return ans; }
        
        int q=0,w=0;
        int p=r-1,o=c-1;
        while(q<=p && w<=o){
            for(int i=w; i<=o && w<=o && q<=p;i++){
                ans.push_back(matrix[q][i]);
            }
            q++;
            for(int i=q; i<=p && q<=p && w<=o;i++){
                ans.push_back(matrix[i][o]);
            }
            o--;
            for(int i=o; i>=w && w<=o && q<=p;i--){
                ans.push_back(matrix[p][i]);
            }
            p--;
            for(int i=p; i>=q && q<=p && w<=o;i--){
                ans.push_back(matrix[i][w]);
            }
            w++;
        }
        return ans;
    }
};