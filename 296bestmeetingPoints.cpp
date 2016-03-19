//
//
//
//A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
//
//For example, given three people living at (0,0), (0,4), and (2,2):
//1 - 0 - 0 - 0 - 1
//|   |   |   |   |
//0 - 0 - 0 - 0 - 0
//|   |   |   |   |
//0 - 0 - 1 - 0 - 0
//
//The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
//
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) 
    {
        if (0 == grid.size() || 0 == grid[0].size())
        {
            return 0;
        }
        
        vector<int>rows;
        vector<int>cols;
        
        int n = grid.size(), m = grid[0].size();
        
        for ( int i = 0; i < n; i++)
        {
            for ( int j = 0; j < m; j++)
            {
                if ( grid[i][j] == 1)
                {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        
        int middlepointx = rows[rows.size()/2];
        int middlepointy = cols[cols.size()/2];
        
        int dist_x = 0, dist_y = 0;
        for ( int i = 0; i < rows.size(); i++)
        {
            dist_x += abs(rows[i] - middlepointx);
        }
        for ( int i = 0; i < cols.size(); i++)
        {
            dist_y += abs(cols[i] - middlepointy);
        }
        
        return (dist_x+dist_y);
    }
};
