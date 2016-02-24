//Given an unsorted integer array, find the first missing positive integer. 
//
//For example,
// Given [1,2,0] return 3,
//  and [3,4,-1,1] return 2. 
//
//  Your algorithm should run in O(n) time and uses constant space. 




void swap(vector<int>& nums, int a, int b)
{
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        if ( 0 == nums.size() )
        {
            return 1;
        }
        for ( int i = 0; i < nums.size(); i++)
        {
            if ( nums[i] == i+1)
            {
                continue;
            }
            
            while( nums[i] > 0 && nums[i] <= nums.size() && nums[i] != i+1 && nums[nums[i]-1] != nums[i])
            {
                swap(nums, nums[i]-1, i);
            }
        }
        
        for ( int i = 0; i < nums.size(); i++)
        {
            if ( nums[i] != i+1)
            {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};
