//Given a collection of numbers that might contain duplicates, return all possible unique permutations. 
//
//For example,
//[1,1,2] have the following unique permutations:
//[1,1,2], [1,2,1], and [2,1,1]. 
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
        if (i> 0 && nums[i] == nums[i-1] &&isvisited[i-1] == 0)
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
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>>result;
        vector<int>set;
        vector<int>isvisited(nums.size(), 0);
        
        permute_helper(nums, set, isvisited, result);
        
        return result;
    }
};
