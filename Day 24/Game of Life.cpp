class Solution {
public:
    void DFS(vector<vector<int>>& M, int i, int j, int& count) {
        if ((i >= 0 && i < M.size() && j >= 0 && j < M[0].size())) {
            if (M[i][j] == 1 || M[i][j]==-1)
                count++;
        }
        return;
    }
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int count = 0;
                DFS(board, i + 1, j, count);
                DFS(board, i, j + 1, count);
                DFS(board, i - 1, j, count);
                DFS(board, i, j - 1, count);
                DFS(board, i + 1, j + 1, count);
                DFS(board, i - 1, j - 1, count);
                DFS(board, i + 1, j - 1, count);
                DFS(board, i - 1, j + 1, count);
                if (board[i][j]==1){
                    if(count==2 || count==3){
                        continue;
                    }
                    else if(count < 2 || count > 3){
                        board[i][j]=-1;
                    }
                }
                else if(board[i][j]==0){
                    if(count==3){
                        board[i][j]=2;
                    }
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j]==2) board[i][j]=1;
                else if(board[i][j]==-1) board[i][j]=0;
            }

        }
        return;
    }
};
