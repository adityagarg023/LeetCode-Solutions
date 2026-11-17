class Solution
{
public:
    bool safe(int row, int col, int n, vector<string> &board)
    {
        for (int y = 0; y < col; y++)
            if (board[row][y] == 'Q')
                return false;
        for (int x = row, y = col; x >= 0 && y >= 0; x--, y--)
            if (board[x][y] == 'Q')
                return false;
        for (int x = row, y = col; x < n && y >= 0; x++, y--)
            if (board[x][y] == 'Q')
                return false;
        return true;
    }

    void backtracking(int col, int n, vector<vector<string>> &ans, vector<string> &board)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
            if (safe(row, col, n, board))
            {
                board[row][col] = 'Q';
                backtracking(col + 1, n, ans, board);
                board[row][col] = '.';
            }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        backtracking(0, n, ans, board);
        return ans;
    }
};