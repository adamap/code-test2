//Find the contiguous subarray within an array (containing at least one number) which has the largest product. 
//
//For example, given the array [2,3,-2,4],
// the contiguous subarray [2,3] has the largest product = 6. 
//

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        if ( 0 == nums.size())
        {
            return 0;
        }
        int localmin = nums[0];
        int localmax = nums[0];
        int globalmax = nums[0];
        
        for ( int i = 1; i < nums.size(); i++)
        {
            int temp = localmax;
            localmax = max(localmin*nums[i], max(nums[i], localmax*nums[i]));
            localmin = min(temp*nums[i], min(nums[i], localmin*nums[i]));
            
            globalmax = max(globalmax, localmax);
        }
        
        return globalmax;
        
    }
};
