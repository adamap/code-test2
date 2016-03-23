//
//
//
//Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph. 
//
//Example 1:
//
//     0          3
//     |          |
//     1 --- 2    4
//
//
//    Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2. 
//
//    Example 2:
//
//      0           4
//      |           |
//      1 --- 2 --- 3
//
//
//    Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1. 
//
//
int countComponents_bfs(int n, vector<pair<int, int>>& edges) 
{
    vector<int>subsets;
    vector<vector<int>>result_set;
    
    vector<int>visited(n, 0);
        
    unordered_map<int, vector<int>> neighbors;
        
    for ( int i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i].first].push_back(edges[i].second);
        neighbors[edges[i].second].push_back(edges[i].first);
    }
        
    queue<int>q;
    int result = 0;
        
    for ( int i = 0; i < n; i++)
    {
        if ( visited[i] == 0)
        {
            result++;
            visited[i] == 1;
            q.push(i);
            while(!q.empty())
            {
                int node = q.front();
                
                subsets.push_back(node);
                
                q.pop();
                for ( int j = 0; j < neighbors[node].size(); j++)
                {
                    if ( visited[neighbors[node][j]] == 0)
                    {
                        q.push(neighbors[node][j]);
                        visited[neighbors[node][j]] = 1;
                    }
                }
            }
            
            sort(subsets.begin(), subsets.end());
            result_set.push_back(subsets);
        }
    }
    return result;
}

void countComponents_dfs_helper(int node, unordered_map<int, vector<int>> neighbors, vector<int>&visited )
{
    visited[node] = 1;
    
    for ( int j = 0; j < neighbors[node].size(); j++)
    {
        if (visited[neighbors[node][j]] == 0 )
        {
            countComponents_dfs_helper(neighbors[node][j], neighbors, visited);
        }
    }
}

int countComponents_dfs(int n, vector<pair<int, int>>& edges) 
{
    vector<int>visited(n, 0);
        
    unordered_map<int, vector<int>> neighbors;
        
    for ( int i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i].first].push_back(edges[i].second);
        neighbors[edges[i].second].push_back(edges[i].first);
    }
    
    int result = 0;
    
    for (int i = 0; i < n; i++)
    {
        if ( visited[i] == 0)
        {
            result++;
            countComponents_dfs_helper(i, neighbors, visited);
        }
    }
    
    return result;

}

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) 
    {
        return countComponents_bfs(n, edges);
        //return countComponents_dfs(n, edges);
    }
};
