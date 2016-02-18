//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
//
//
//For example,
//
//Consider the following matrix: 
//[
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
//  ]
//
//
//      Given target = 3, return true.
//
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if ( 0 == matrix.size() || 0 == matrix[0].size())
        {
            return 0;
        }
        
        int n = matrix.size(), m= matrix[0].size();
        
        int start = 0, end = n-1;
        while (start+1 < end)
        {
            int mid = start + (end - start)/2;
            
            if ( matrix[mid][0] == target)
            {
                return 1;
            }
            else if ( matrix[mid][0] < target)
            {
                start = mid;
            }
            else 
            {
                end = mid;
            }
        }
        
        if ( matrix[start][0] == target)
        {
            return 1;
        }
        if ( matrix[end][0] == target)
        {
            return 1;
        }

        int row = 0;
        if ( matrix[start][0] > target )
        {
            return 0;
        }
        else if (matrix[end][0] < target)
        {
            row = end;
        }
        else
        {
            row = start;
        }
        
        start = 0, end = m-1;
        
        while (start+1 < end)
        {
            int mid = start + (end - start)/2;
            
            if ( matrix[row][mid] == target)
            {
                return 1;
            }
            else if ( matrix[row][mid] < target)
            {
                start = mid;
            }
            else 
            {
                end = mid;
            }
        }
  
        if ( matrix[row][start] == target)
        {
            return 1;
        }
        if ( matrix[row][end] == target)
        {
            return 1;
        }
      
        return 0;
    }
};
