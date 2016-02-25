//Given a collection of distinct numbers, return all possible permutations. 
//
//For example,
//[1,2,3] have the following permutations:
//[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
//
//




void permute_helper(vector<int>nums, vector<int>set, vector<int>isvisited, vector<vector<int>>&result)
{
    
    if (set.size() == nums.size() )
    {
        result.push_back(set);
        return;
    }
    
    for ( int i = 0; i < nums.size(); i++)
    {
        if (isvisited[i] == 1 )
        {
            continue;
        }
        set.push_back(nums[i]);
        isvisited[i] = 1;
        permute_helper(nums, set, isvisited, result);
        set.pop_back();
        isvisited[i] = 0;
    }
}


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>result;
        vector<int>set;
        vector<int>isvisited(nums.size(), 0);
        
        permute_helper(nums, set, isvisited, result);
        
        return result;
    }
};
