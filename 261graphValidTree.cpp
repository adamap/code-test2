//
//
//Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree. 
//
//For example: 
//
//Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true. 
//
//Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false. 
//
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) 
    {
    if (n - 1 != edges.size())
    {
    return 0;
    }
    if ( n == 1 && edges.size() == 0)
    {
        return 1;
    }

        vector<int>visited(n, 0);
        
        unordered_map<int, vector<int>> neighbors;
        
        for ( int i = 0; i < edges.size(); i++)
        {
            neighbors[edges[i].first].push_back(edges[i].second);
            neighbors[edges[i].second].push_back(edges[i].first);
        }
        stack<int>s;
    s.push(edges[0].first);
    
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            if ( visited[node] == 1)
            {
                return 0;
            }
            
            visited[node] = 1;
            for ( int j = 0; j < neighbors[node].size(); j++)
            {
                if(visited[neighbors[node][j]] == 0)
                {
                    s.push(neighbors[node][j]);
                }
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if ( visited[i] == 0)
            {
                return 0;
            }
        }
        return 1;
    }
};
