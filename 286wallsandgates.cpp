//
//
//
//You are given a m x n 2D grid initialized with these three possible values.
//1.-1 - A wall or an obstacle.
//2.0 - A gate.
//3.INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
//
//Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
//
//For example, given the 2D grid:
//
//INF  -1  0  INF
//INF INF INF  -1
//INF  -1 INF  -1
//  0  -1 INF INF
//
//
//  After running your function, the 2D grid should be:
//
//    3  -1   0   1
//    2   2   1  -1
//    1  -1   2  -1
//    0  -1   3   4
//


void wallsAndGates_helper(vector<vector<int>>& rooms, int i, int j, int level)
{
    if ( i < 0 || i >= rooms.size() || j < 0 || j >= rooms[0].size() )
    {
        return;
    }
    
    if ( rooms[i][j] >= level)
    {
        rooms[i][j] = level;
        wallsAndGates_helper(rooms, i+1, j, level+1);
        wallsAndGates_helper(rooms, i-1, j, level+1);
        wallsAndGates_helper(rooms, i, j+1, level+1);
        wallsAndGates_helper(rooms, i, j-1, level+1);
    }
}

void wallsAndGates_dfs(vector<vector<int>>& rooms) 
{
    int n = rooms.size(), m = rooms[0].size();
        
    for ( int i = 0; i < n; i++)
    {
        for ( int j = 0; j < m; j++)
        {
            if ( rooms[i][j] == 0)
            {
                wallsAndGates_helper(rooms, i, j, 0);
            }
        }
    }
}

void wallsAndGates_bfs(vector<vector<int>> &rooms)
{
    queue<pair<int, int> > q;
    int n = rooms.size(), m = rooms[0].size();
        
    for ( int i = 0; i < n; i++)
    {
        for ( int j = 0; j < m; j++)
        {
            if ( rooms[i][j] == 0)
            {
                q.push(make_pair(i, j));
            }
        }
    }
    
    vector<vector<int>> steps{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        
        for ( int i = 0 ; i < steps.size(); i++)
        {
            int x_next = x+steps[i][0], y_next = y+steps[i][1];
            if ( x_next < 0 || x_next >= rooms.size() || y_next < 0 || y_next >= rooms[0].size() || rooms[x_next][y_next] < rooms[x][y]+1 )
            {
                continue;
            }
            
            rooms[x_next][y_next] = rooms[x][y]+1;
            q.push(make_pair(x_next, y_next));
        }
    }
}

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        if ( 0 == rooms.size() || 0 == rooms[0].size())
        {
            return;
        }
        
        //wallsAndGates_dfs( rooms); 
        wallsAndGates_bfs( rooms); 
    }
};
