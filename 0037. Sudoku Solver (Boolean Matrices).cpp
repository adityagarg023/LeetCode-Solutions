class Solution
{
public:
    bool row[9][10] = {false};
    bool col[9][10] = {false};
    bool box[9][10] = {false};

    void solveSudoku(vector<vector<char>> &board)
    {
        for (int r = 0; r < 9; r++)
            for (int c = 0; c < 9; c++)
                if (board[r][c] != '.')
                {
                    int num = board[r][c] - '0';
                    int b = (r / 3) * 3 + (c / 3);
                    row[r][num] = col[c][num] = box[b][num] = true;
                }
        backtracking(board);
    }

    bool backtracking(vector<vector<char>> &board)
    {
        int bestR = -1, bestC = -1;
        int min = 10;
        for (int r = 0; r < 9; r++)
            for (int c = 0; c < 9; c++)
                if (board[r][c] == '.')
                {
                    int b = (r / 3) * 3 + (c / 3);
                    int count = 0;
                    for (int num = 1; num <= 9; num++)
                        if (!row[r][num] && !col[c][num] && !box[b][num])
                            count++;
                    if (count < min)
                    {
                        min = count;
                        bestR = r;
                        bestC = c;
                    }
                }
        if (bestR == -1)
            return true;
        int b = (bestR / 3) * 3 + (bestC / 3);
        for (int num = 1; num <= 9; num++)
            if (!row[bestR][num] && !col[bestC][num] && !box[b][num])
            {
                board[bestR][bestC] = num + '0';
                row[bestR][num] = col[bestC][num] = box[b][num] = true;
                if (backtracking(board))
                    return true;
                board[bestR][bestC] = '.';
                row[bestR][num] = col[bestC][num] = box[b][num] = false;
            }
        return false;
    }
};