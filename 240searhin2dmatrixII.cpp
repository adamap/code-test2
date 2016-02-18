//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.
//
//
//For example,
//
//Consider the following matrix: 
//[
//  [1,   4,  7, 11, 15],
//  [2,   5,  8, 12, 19],
//  [3,   6,  9, 16, 22],
//  [10, 13, 14, 17, 24],
//  [18, 21, 23, 26, 30]
// ]
//
//
// Given target = 5, return true.
//
// Given target = 20, return false.



bool searchMatrix_omn(vector<vector<int>>& matrix, int target)
{
    if ( 0 == matrix.size() || 0 == matrix[0].size())
    {
        return 0;
    }
        
    int n = matrix.size()-1, m = matrix[0].size()-1;
        
    int start_x = 0, start_y = m;
        
    while ( start_x <= n && start_y >= 0)
    {
        if ( matrix[start_x][start_y] == target)
        {
            return 1;
        }
        else if ( matrix[start_x][start_y] > target)
        {
            start_y--;
        }
        else 
        {
            start_x ++;
        }
    }
    return 0;
}

bool searchMatrix_recurhelper(vector<vector<int>>& matrix, int start_x, int start_y, int end_x, int end_y, int target)
{
  
  if (start_x > end_x || start_y > end_y)
  {
    return 0;
  }

  int mid_x = start_x + (end_x - start_x) / 2;
  int mid_y = start_y + (end_y - start_y) / 2;

  if (matrix[mid_x][mid_y] == target)
  {  
    return 1;
  }
  else
  {
    if (start_x == end_x && start_y + 1 == end_y)
    {
      return (matrix[start_x][end_y] == target);
    }
    if (start_x+1 == end_x && start_y == end_y)
    {
      return (matrix[end_x][start_y] == target);
    }


   if (matrix[mid_x][mid_y] < target) 
   {
     return    searchMatrix_recurhelper(matrix, mid_x + 1, mid_y + 1, end_x, end_y, target)
            || searchMatrix_recurhelper(matrix, start_x, mid_y + 1, mid_x, end_y, target)
            || searchMatrix_recurhelper(matrix, mid_x + 1, start_y, end_x, mid_y, target);
   }
   else
   {
     return    searchMatrix_recurhelper(matrix, start_x, start_y, mid_x - 1, mid_y - 1, target)
            || searchMatrix_recurhelper(matrix, start_x, mid_y, mid_x - 1, end_y, target)
            || searchMatrix_recurhelper(matrix, mid_x, start_y, end_x, mid_y - 1, target);     
   }
  }
}

bool searchMatrix_recur(vector<vector<int>>& matrix, int target)
{
    if ( 0 == matrix.size() || 0 == matrix[0].size())
    {
        return 0;
    }
    
    int n = matrix.size()-1, m = matrix[0].size()-1;
    return searchMatrix_recurhelper( matrix, 0, 0, n, m, target );  
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        return searchMatrix_omn(matrix, target);
        
        //return searchMatrix_recur( matrix, target);
    }
};
