//Given a collection of integers that might contain duplicates, nums, return all possible subsets. 
//
//Note:
//
//Elements in a subset must be in non-descending order.
//The solution set must not contain duplicate subsets.
//
//
//For example,
// If nums = [1,2,2], a solution is: 
// [
//   [2],
//     [1],
//       [1,2,2],
//         [2,2],
//           [1,2],
//             []
//             ]
//



void subsetsWithDup_helper(vector<int>& nums, int index, vector<int>set, vector<vector<int>>&result)
{
    result.push_back(set);
    
    for ( int i = index; i < nums.size(); i++)
    {
        if ( i > index && nums[i] == nums[i-1])
        {
            continue;
        }
        set.push_back(nums[i]);
        subsetsWithDup_helper(nums, i+1, set, result);
        set.pop_back();
        
    }
    
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        vector<int>set;
        
        subsetsWithDup_helper( nums, 0, set, result);
        
        return result;
    }
};
