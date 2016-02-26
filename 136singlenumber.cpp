//Given an array of integers, every element appears twice except for one. Find that single one.

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        if (0 == nums.size())
        {
            return 0;
        }
        int ret = nums[0];
        
        for ( int i = 1; i < nums.size(); i++)
        {
            ret = ret^nums[i];
        }
        
        return ret;
    }
};
