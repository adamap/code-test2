//
//
//
//
//
//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses? 
//
//For example:
//2, [[1,0]]
//
//There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
//2, [[1,0],[0,1]]
//
//There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
//



nt canFinish_dfs_helper(int index, vector<int>&visited, unordered_map<int, vector<int>>&adjlist)
{
    if (visited[index] == -1)
    {
        return 0;
    }
    
    if (visited[index] == 1)
    {
        return 1;
    }
    
    visited[index] = -1;
    
    if ( adjlist.find(index) != adjlist.end())
    {
        vector<int>neighbors = adjlist[index];
    
        if (neighbors.size() > 0)
        {
            for ( int i = 0; i < neighbors.size(); i++)
            {
                if (0 == canFinish_dfs_helper(neighbors[i], visited, adjlist))
                {
                    return 0;
                }
            }
        }
    }
    
    visited[index] = 1;
    return 1;
}

bool canFinish_dfs(int numCourses, vector<pair<int, int>>& prerequisites)
{
    if (numCourses <= 0)
    {
        return 1;
    }
    
    if ( prerequisites.size() == 0)
    {
        return 1;
    }
    
    unordered_map<int, vector<int>>adjlist;
    
    for ( int i = 0; i < prerequisites.size(); i++)
    {
        adjlist[prerequisites[i].second].push_back(prerequisites[i].first);
    }
    
    vector<int>visited(numCourses, 0);
    
    for ( int i = 0; i < numCourses; i++)
    {
        if (0 == canFinish_dfs_helper(i, visited, adjlist))
        {
            return 0;
        }
    }
    return 1;
}


bool canFinish_bfs(int numCourses, vector<pair<int, int>>& prerequisites)
{
    if (numCourses <= 0)
    {
        return 1;
    }
    
    if ( prerequisites.size() == 0)
    {
        return 1;
    }
    
    unordered_map<int, vector<int>>adjlist;
    vector<int> in(numCourses, 0);
    
    for ( int i = 0; i < prerequisites.size(); i++)
    {
        adjlist[prerequisites[i].second].push_back(prerequisites[i].first);
        in[prerequisites[i].first]++;
    }
    
    queue<int>q;
   
    for ( int i = 0; i < numCourses; i++)
    {
        if ( in[i] == 0)
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        
        if ( adjlist.find(t) != adjlist.end())
        {
            vector<int>neighbors = adjlist[t];
    
            if (neighbors.size() > 0)
            {
                for ( int i = 0; i < neighbors.size(); i++)
                {
                    in[neighbors[i]]--;
                    if ( in[neighbors[i]] == 0)
                    {
                        q.push(neighbors[i]);
                    }
                }
            }
        }
    }
    
    for (int i= 0; i < numCourses; i++)
    {
        if (in[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        //return canFinish_dfs(numCourses, prerequisites);
        return canFinish_bfs(numCourses, prerequisites);
    }
};
