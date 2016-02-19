//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution.
//
//Example:
//
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].
//
//
//
//UPDATE (2016/2/13):
// The return format had been changed to zero-based indices. Please read the above updated description carefully. 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int>hash_map;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++)
        {
            hash_map[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if ( hash_map.find(target- nums[i]) != hash_map.end() && i != hash_map[target- nums[i]])
            {
                result.push_back(i);
                result.push_back(hash_map[target- nums[i]]);
                break;
            }
        }
        return result;
    }
};
