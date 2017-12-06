class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board){
        for (int i = 0; i < 9; i++){
            bool row[10] = { false };
            bool col[10] = { false };
            bool bank[10] = { false };
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    if (row[board[i][j] - '0'])  return false;
                    else row[board[i][j] - '0'] = true;
                }
                if (board[j][i] != '.'){
                    if (col[board[j][i] - '0'] == true)  return false;
                    else col[board[j][i] - '0'] = true;
                }
                if (board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] != '.'){
                    if (bank[board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] - '0']) return false;
                    else bank[board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] - '0'] = true;
                }
            }
        }
        return true;
    }
};