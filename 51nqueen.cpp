//
//
//The n-queens puzzle is the problem of placing n queens on an n¡n chessboard such that no two queens attack each other.
//
//Given an integer n, return all distinct solutions to the n-queens puzzle.
//
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
//For example,
// There exist two distinct solutions to the 4-queens puzzle:
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
//   ]
//
nt availablepos(vector<string> board, int row, int col, int n)
{
  for (int i = 0; i < row; i++)
  {
    if (board[i][col] == 'Q')
    {
      return 0;
    }
  }

  for (int i = row-1, j= col-1; i >= 0 && j>=0; i--, j--)
  {
    if (board[i][j] == 'Q')
    {
      return 0;
    }
  }
  for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
  {
    if (board[i][j] == 'Q')
    {
      return 0;
    }
  }
  return 1;
  }

void solveNQueens_helper(int n, vector<string> board, vector<vector<string>>&result, int row)
{
  if (row == n)
  {
    result.push_back(board);
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (1 == availablepos(board, row, i, n))
    {
      board[row][i] = 'Q';
      solveNQueens_helper(n, board, result, row + 1);
      board[row][i] = '.';
    }
  }
}

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>result;

        vector<string>board(n, string(n, '.'));
 
        solveNQueens_helper(n, board, result, 0);

        return result;
    }
};               
