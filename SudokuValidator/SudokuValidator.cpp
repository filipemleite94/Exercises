class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool lin[9][9], col[9][9], square[9][9];
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                lin[i][j] = false;
                col[i][j] = false;
                square[i][j] = false;
            }
        }
        for(int i = 0; i < 9; i++){
            for(int j = 0; j<9; j++){
                char c = board[i][j];
                if(c=='.')
                    continue;
                c = c-'1';
                if(lin[i][c])
                    return false;
                else
                    lin[i][c] = true;
                if(col[j][c])
                    return false;
                else
                    col[j][c] = true;
                if(square[(3*(i/3) + j/3)][c])
                    return false;
                else
                    square[(3*(i/3) + j/3)][c] = true;
            }
        }
        return true;
    }
};