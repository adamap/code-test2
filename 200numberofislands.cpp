//Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
//Example 1:
//11110
//11010
//11000
//00000
//
//Answer: 1
//
//Example 2:
//11000
//11000
//00100
//00011
//
//Answer: 3
//
void setadjacenttozero(vector<vector<char>>&grid, int i, int j)
{
    int n = grid.size(), m = grid[0].size();

    grid[i][j] = '0';
    
    if ( i > 0 && grid[i-1][j] == '1')
    {
        setadjacenttozero(grid, i-1, j);
    }
    
    if ( i+1 < n && grid[i+1][j] == '1')
    {
        setadjacenttozero(grid, i+1, j);
    }
    
    if ( j > 0 && grid[i][j-1] == '1')
    {
        setadjacenttozero(grid, i, j-1);
    }
    if ( j+1 < m && grid[i][j+1] == '1')
    {
        setadjacenttozero(grid, i, j+1);
    }
    
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if (0 == grid.size() || 0 == grid[0].size())
        {
            return 0;
        }
        int n = grid.size(), m = grid[0].size();
        
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for ( int j = 0; j < m; j++)
            {
                if ( grid[i][j] == '1')
                {
                    count++;
                    setadjacenttozero(grid, i, j);
                }
            }
        }
        
        return count;
    }
};
