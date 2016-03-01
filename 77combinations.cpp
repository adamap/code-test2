//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n. 
//
//For example,
// If n = 4 and k = 2, a solution is: 
// [
//   [2,4],
//   [3,4],
//    [2,3],
//    [1,2],
//    [1,3],
//    [1,4],
//  ]
//  
//




//void combine_helper(int n, int k,  vector<int>isvisited, int index, vector<int>set, vector<vector<int>>&result)
void combine_helper(int n, int k, int index, vector<int>set, vector<vector<int>>&result)
{
    if ( set.size() == k)
    {
        result.push_back(set);
        return;
    }
    
    for ( int i = index; i <= n; i++)
    {
        //if ( isvisited[i-1] == 1)
        //{
        //    continue;
        //}
        //isvisited[i-1] = 1;
        set.push_back(i);
        //combine_helper(n, k, isvisited, i+1, set, result);
        combine_helper(n, k, i+1, set, result);
        set.pop_back();
        //isvisited[i-1] = 0;
    }
}


class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>>result;
        vector<int>set;
        
        //vector<int>isvisited(n, 0);
        
        //combine_helper(n, k, isvisited, 1, set, result);
        combine_helper(n, k, 1, set, result);
        
        return result;
    }
};
