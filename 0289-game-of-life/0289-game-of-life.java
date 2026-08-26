class Solution {
    int n, m;
    public int cntnbr(int[][] board, int i, int j) {
        int count = 0;

        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di == 0 && dj == 0) continue;

                int ni = i + di;
                int nj = j + dj;

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && board[ni][nj] == 1) count++;
            }
        }
        return count;
    }
    public void gameOfLife(int[][] board) {
        n = board.length;
        m = board[0].length;

        int[][] old = new int[n][m];

        for (int i = 0; i < n; i++) old[i] = board[i].clone();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = cntnbr(old, i, j);
                if (old[i][j] == 1) {
                    if (cnt < 2 || cnt > 3)
                        board[i][j] = 0;
                }
                else {
                    if (cnt == 3)
                        board[i][j] = 1;
                }
            }
        }
    }
}