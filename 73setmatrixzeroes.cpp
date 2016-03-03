//
//
//
//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place. 
//
//click to show follow up.
//
//Follow up: 
//Did you use extra space?
// A straight forward solution using O(mn) space is probably a bad idea.
//  A simple improvement uses O(m + n) space, but still not the best solution.
//   Could you devise a constant space solution? 
//

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        if(0 == matrix.size() || 0 == matrix[0].size())
        {
            return;
        }
        
        int m = matrix.size(), n = matrix[0].size();
        
        vector<int>row(n, 1);
        vector<int>col(m, 1);
        
        for ( int i = 0; i < m; i++)
        {
            for ( int j = 0; j < n; j++)
            {
                if ( matrix[i][j] == 0)
                {
                    row[j] = 0;
                    col[i] =0;
                }
            }
        }
        
        for ( int i = 0; i < m; i++)
        {
            if ( col[i] == 0)
            {
                for ( int j = 0; j < n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for ( int i = 0; i < n; i++)
        {
            if ( row[i] == 0)
            {
                for ( int j = 0; j < m; j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        
        
    }
};
