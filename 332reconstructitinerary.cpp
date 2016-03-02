//
//
//
//
//Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK. 
//
//Note:
//
//1.If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
//2.All airports are represented by three capital letters (IATA code).
//3.You may assume all tickets form at least one valid itinerary.
//
//
//Example 1:
//tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
// Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
//
//
// Example 2:
// tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
//  Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
//  Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order. 






int findItinerary_dfs1_helper(string cur_str, vector<string> &result, int n, unordered_map<string, map<string, int>>&hash_map)
{
    if ( result.size() == n)
    {
        return 1;
    }
    map<string, int>::iterator it;
    
    for (it = hash_map[cur_str].begin(); it != hash_map[cur_str].end(); it++) 
    {
        if ( it->second != 0)
        {
            it->second--;
            result.push_back(it->first);
            if (1 == findItinerary_dfs1_helper(it->first, result, n, hash_map))
            {
                return 1;
            }
            result.pop_back();
            it->second++;
        }
    }
    return 0;    
}

vector<string> findItinerary_dfs1(vector<pair<string, string>> tickets)
{
    unordered_map<string, map<string, int>>hash_map;
    
    for ( int i = 0; i < tickets.size(); i++)
    {
        hash_map[tickets[i].first][tickets[i].second]++;
    }
    
    string start = "JFK";
    vector<string>result;
    
    result.push_back(start);
    
    findItinerary_dfs1_helper(start, result, tickets.size()+1, hash_map);
    return result;    
}

void findItinerary_dfs2_helper(string cur_str, vector<string>&result, unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &hash_map)
{
    while(hash_map.find(cur_str) != hash_map.end() && !hash_map[cur_str].empty())   
    {
        string temp = hash_map[cur_str].top();
        hash_map[cur_str].pop();
        findItinerary_dfs2_helper(temp, result, hash_map);        
    }
    
    result.push_back(cur_str);
}

vector<string> findItinerary_dfs2(vector<pair<string, string>> tickets)
{
    vector<string>result;
    
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> hash_map;
    
    for ( int i = 0; i < tickets.size(); i++)
    {
        hash_map[tickets[i].first].push( tickets[i].second );
    }
    
    string start = "JFK";
    //result.push_back(start);
    
    findItinerary_dfs2_helper(start, result, hash_map);
    
    reverse(result.begin(), result.end());
    return result;
}

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) 
    {
        //vector<string> ret = findItinerary_dfs1(tickets);
        
        vector<string> ret = findItinerary_dfs2(tickets);
        return ret;
    }
};
