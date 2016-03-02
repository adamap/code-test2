//
//http://www.lintcode.com/en/problem/topological-sorting/
//
//
//Given an directed graph, a topological order of the graph nodes is defined as follow:
//For each directed edge A -> B in graph, A must before B in the order list.
//The first node in the order can be any node in the graph with no nodes direct to it.
//
//Find any topological order for the given graph.
//
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

void topSortdfs_helper(DirectedGraphNode*graphnode, unordered_map<DirectedGraphNode*, int>&isVisited, stack<DirectedGraphNode*>&stk)
{
    isVisited[graphnode] = 1;
    
    for ( int i = 0; i < graphnode->neighbors.size(); i++)
    {
        if (isVisited[graphnode->neighbors[i]] == 0 )
        {
            topSortdfs_helper(graphnode->neighbors[i], isVisited, stk);
        }
    }
    
    stk.push(graphnode);
}
 
vector<DirectedGraphNode*> topSortdfs(vector<DirectedGraphNode*> graph)  
{
    stack<DirectedGraphNode*>stk;
    
    unordered_map<DirectedGraphNode*, int>isVisited;

    for (int i = 0; i < graph.size(); i++)
    {
        if (isVisited[graph[i]] == 0 )
        {
            topSortdfs_helper(graph[i], isVisited, stk);
        }
    }
     
    vector<DirectedGraphNode*>result; 
    while(!stk.empty())
    {
        result.push_back(stk.top());
        stk.pop();
    }
    
    return result;
}

vector<DirectedGraphNode*> topSortbfs(vector<DirectedGraphNode*> graph) 
{
    unordered_map<DirectedGraphNode*, int>hash_map;
    
    for ( int i = 0; i < graph.size(); i++)
    {
        for ( int j = 0; j < graph[i]->neighbors.size(); j++)
        {
            hash_map[graph[i]->neighbors[j]]++;
        }
    }
    
    vector<DirectedGraphNode*>result;
    queue<DirectedGraphNode*>q;
    
    for ( int i = 0; i < graph.size(); i++)
    {
        if ( hash_map.find(graph[i]) == hash_map.end())
        {
            q.push(graph[i]);
            result.push_back(graph[i]);
        }
    }
    
    while(!q.empty())
    {
        
        DirectedGraphNode* node = q.front();
        q.pop();
        
        for ( int i = 0; i < node->neighbors.size(); i++)
        {
            hash_map[node->neighbors[i]]--;
            if (hash_map[node->neighbors[i]] == 0)
            {
                result.push_back(node->neighbors[i]);
                // only push when node is not longer to be visited
                q.push(node->neighbors[i]);
            }
        }
    }
    return result;
}


class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) 
    {
        // write your code here
        if (0 == graph.size())
        {
            return graph;
        }
        
        //unordered_map<DirectedGraphNode*, int>hash_map;
        //for (int i = 0; i < graph.size(); i++)
        //{
        //    for ( int j = 0; j < graph[i]->neighbors.size(); j++)
        //    {
        //        if (hash_map.find(graph[i]->neighbors[j]) == hash_map.end())
        //        {
        //            hash_map[graph[i]->neighbors[j]] = 1;
        //        }
        //       else
        //        {
        //            hash_map[graph[i]->neighbors[j]]++;
        //        }
        //    }
        //}
        //vector<DirectedGraphNode*>result;
        //queue<DirectedGraphNode*>q;
        //for (int i = 0; i < graph.size(); i++)
        //{
        //    if (hash_map.find(graph[i]) == hash_map.end() )
        //    {
        //        result.push_back(graph[i]);
        //        q.push(graph[i]);
        //    }
        //}
        
        //while(!q.empty())
        //{
        //    DirectedGraphNode* node = q.front();
        //    q.pop();
        //    
        //    for ( int j = 0; j < node->neighbors.size(); j++)
        //    {
        //        hash_map[node->neighbors[j]]--;
        //        if ( 0 == hash_map[node->neighbors[j]])
        //        {
        //            result.push_back(node->neighbors[j]);
        //            q.push(node->neighbors[j]);
        //      }
        //    }
        //}
        //vector<DirectedGraphNode*>result = topSortbfs(graph); 
        vector<DirectedGraphNode*>result = topSortdfs(graph);
        return result;
        
        
    }
};
