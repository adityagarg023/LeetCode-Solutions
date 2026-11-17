class Solution
{
public:
    bool valid(vector<vector<char>> &board, int row, int col, int num)
    {
        for (int i = 0; i < 9; i++)
            if (board[row][i] == num + '0')
                return false;
        for (int i = 0; i < 9; i++)
            if (board[i][col] == num + '0')
                return false;
        int startR = (row / 3) * 3;
        int startC = (col / 3) * 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[startR + i][startC + j] == num + '0')
                    return false;
        return true;
    }

    int count(vector<vector<char>> &board, int row, int col)
    {
        int count = 0;
        for (int num = 1; num <= 9; num++)
            if (valid(board, row, col, num))
                count++;
        return count;
    }

    bool backtracking(vector<vector<char>> &board)
    {
        int bestR = -1, bestC = -1;
        int min = 10;
        for (int row = 0; row < 9; row++)
            for (int col = 0; col < 9; col++)
                if (board[row][col] == '.')
                {
                    int options = count(board, row, col);
                    if (options < min)
                    {
                        min = options;
                        bestR = row;
                        bestC = col;
                    }
                }
        if (bestR == -1)
            return true;
        for (int num = 1; num <= 9; num++)
            if (valid(board, bestR, bestC, num))
            {
                board[bestR][bestC] = num + '0';
                if (backtracking(board))
                    return true;
                board[bestR][bestC] = '.';
            }
        return false;
    }

    void solveSudoku(vector<vector<char>> &board) { backtracking(board); }
};