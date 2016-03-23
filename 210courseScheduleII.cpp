//
//
//
//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
//
//There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array. 
//
//For example:
//2, [[1,0]]
//
//There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
//4, [[1,0],[2,0],[3,1],[3,2]]
//
//There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
//

int canFinish_dfs_helper(int index, vector<int>&visited, unordered_map<int, vector<int>>&adjlist, vector<int>&result)
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
    
        for ( int i = 0; i < neighbors.size(); i++)
        {
            if (0 == canFinish_dfs_helper(neighbors[i], visited, adjlist, result))
            {
                return 0;
            }
        }
    }
    
    result.push_back(index);
    visited[index] = 1;
    return 1;
}

vector<int> canFinish_dfs(int numCourses, vector<pair<int, int>>& prerequisites)
{
    vector<int> result;
    
    if (numCourses <= 0)
    {
        return result;
    }
    
    if ( prerequisites.size() == 0)
    {
        for ( int i = 0; i < numCourses; i++)
        {
            result.push_back(i);
        }
        return result;
    }
    
    unordered_map<int, vector<int>>adjlist;
    
    for ( int i = 0; i < prerequisites.size(); i++)
    {
        adjlist[prerequisites[i].second].push_back(prerequisites[i].first);
    }
    
    vector<int>visited(numCourses, 0);
    
    for ( int i = 0; i < numCourses; i++)
    {
        if (0 == canFinish_dfs_helper(i, visited, adjlist, result))
        {
            vector<int>temp;
            return temp;
        }
    }
    return result;
}

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<int> ret = canFinish_dfs(numCourses, prerequisites);
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};
