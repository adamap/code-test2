//
//
//For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels. 
//
//Format
// The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels). 
//
// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges. 
//
// Example 1: 
//
// Given n = 4, edges = [[1, 0], [1, 2], [1, 3]] 
//         0
//         |
//         1
//        / \
//       2   3
//
//
//    return  [1] 
//
//    Example 2: 
//
//    Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]] 
//                  0  1  2
//                   \ | /
//                     3
//                     |
//                     4
//                     |
//                     5
//
//   return  [3, 4] 
//
//
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) 
    {
        vector<int> result;
        if ( n == 1)
        {
            return {0};
        }
        
        vector<int> in(n, 0);
        vector<vector<int>> g(n, vector<int>());
        
        queue<int>q;
        
        for ( int i = 0; i < edges.size(); i++)
        {
            g[edges[i].first].push_back(edges[i].second);
            in[edges[i].first]++;
            g[edges[i].second].push_back(edges[i].first);
            in[edges[i].second]++;
        }
        
        for ( int i = 0; i < n; i++)
        {
            if ( in[i] == 1)
            {
                q.push(i);
            }
        }
        
        while( n > 2)
        {
            int q_size= q.size();
            
            for ( int i = 0; i < q_size; i++)
            {
                int t = q.front();
                q.pop();
                --n;
                
                for ( int j = 0; j < g[t].size(); j++)
                {
                    --in[g[t][j]];
                    if (in[g[t][j]] == 1)
                    {
                        q.push(g[t][j]);
                    }
                }
            }
        }
        
        while(!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }
        
        return result;
    }
};
