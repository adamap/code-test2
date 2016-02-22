//
//Find the contiguous subarray within an array (containing at least one number) which has the largest sum. 
//
//For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
// the contiguous subarray [4,?1,2,1] has the largest sum = 6. 
//
//
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        if ( 0 == nums.size())
        {
            return 0;
        }
        int localmax = nums[0];
        int globalmax = nums[0];
        
        for ( int i = 1; i < nums.size(); i++)
        {
            localmax = max(nums[i], localmax+nums[i]);
            globalmax = max(globalmax, localmax);
        }
        
        return globalmax;
    }
};
