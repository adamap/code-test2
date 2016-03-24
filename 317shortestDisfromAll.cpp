//
//
//You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:
//ŒıŒÈEach 0 marks an empty land which you can pass by freely.
//ŒıŒÈEach 1 marks a building which you cannot pass through.
//ŒıŒÈEach 2 marks an obstacle which you cannot pass through.
//
//For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):
//1 - 0 - 2 - 0 - 1
//|   |   |   |   |
//0 - 0 - 0 - 0 - 0
//|   |   |   |   |
//0 - 0 - 1 - 0 - 0
//
//The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.
//
//Note:
// There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
//

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) 
    {
        if (0 == grid.size() || 0 == grid[0].size())
        {
            return 0;
        }
 
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>distance (n, vector<int>(m, 0));
        vector<vector<int>>accessNums(n, vector<int>(m,0));
 
        int total_building = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vector<vector<int>>visited (n, vector<int>(m, 0));
                if (grid[i][j] == 1)
                {
                    total_building++;
                    queue<pair<int, int> > q;
                    int cur = 1, next = 0;
                    q.push(make_pair(i, j));
                    int level = 0;
    
                    while (!q.empty())
                    {
                        while ( cur > 0)
                        {
                            pair<int, int> pa = q.front();
                            q.pop();
                            cur--;
      
                            int x = pa.first, y = pa.second;
                            
                            if (grid[x][y] == 0)
                            {
                                distance[x][y] += level;
                                accessNums[x][y] ++;
                            }
      
                            if (x+1 < n && grid[x+1][y] == 0 &&visited[x+1][y] == 0)
                            {
                                visited[x+1][y] = 1;
                                q.push(make_pair(x + 1, y));
                                next++;
                            }
      
                            if (x - 1 >= 0 && grid[x - 1][y] == 0&&visited[x-1][y] == 0)
                            {
                                visited[x-1][y] = 1;
                                q.push(make_pair(x - 1, y));
                                next++;
                            }
                            if (y + 1 < m && grid[x ][y+1] == 0&&visited[x][y+1] == 0)
                            {
                                visited[x][y+1] = 1;
                                q.push(make_pair(x , y+1));
                                next++;
                            }
                            if (y - 1 >= 0 && grid[x ][y-1] == 0&&visited[x][y-1] == 0)
                            {
                                visited[x][y-1] = 1;
                                q.push(make_pair(x , y-1));
                                next++;
                            }
                        }
                        cur = next;
                        next = 0;
                        level++;
                    }
                }
            }
        }
 
        int min_dis = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (accessNums[i][j] == total_building)
                {
                    min_dis = min(min_dis, distance[i][j]);
                }
            }
        }
        return (min_dis == INT_MAX)?-1:min_dis;
        
    }
};

