class Solution {
public:
    void move(vector<vector<int>>& matrix, vector<vector<bool>> &vis, int save, int put, int i, int j){
        int n = matrix.size();
        vis[i][j] = 1;
        save = matrix[j][n-1-i];
        matrix[j][n-1-i] = put;
        put = save;
        if(!vis[j][n-1-i]) move(matrix, vis, save, put, j, n-1-i);
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<bool>> vis (n, vector<bool>(n, 0));
        for(int i=0; i<n; i++){
            int save, put;
            for(int j=0; j<n;j++){
                if(!vis[i][j]){
                    put = matrix[i][j];
                    move(matrix,vis,save,put, i,j);
                }
            }
        }

    }
};