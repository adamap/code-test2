//
//
//Follow up for N-Queens problem.
//
//Now, instead outputting board configurations, return the total number of distinct solutions
//
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

void solveNQueens_helper(int n, vector<string> board, int&result, int row)
{
  if (row == n)
  {
    result++;
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
    int totalNQueens(int n) 
    {
        int result = 0;
        
       vector<string>board(n, string(n, '.'));

       solveNQueens_helper(n, board, result, 0);

       return result; 
    }
};
