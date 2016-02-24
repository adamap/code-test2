//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array. 
//
//For example,
// Given nums = [0, 1, 3] return 2. 
//
// Note:
//  Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity? 
//

//xor method
int missingNumberxor(vector<int>& nums)
{
    int x = nums[0];
    
    for ( int i = 1; i < nums.size(); i++)
    {
        x = x^nums[i];
    }
    
    int y = 0;
    
    for ( int i = 1; i < nums.size()+1; i++)
    {
        y = y^i;
    }
    
    return (x^y);
}

//bucket sorting
void swap(vector<int>& nums, int a, int b)
{
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

int missingNumberbs(vector<int>& nums)
{
    for ( int i = 0 ; i < nums.size(); i++)
    {
        if ( nums[i] == i)
        {
            continue;
        }
        while( nums[i] != nums.size() && nums[nums[i]] != nums[i])
        {
            swap(nums, nums[i], i);
        }
    }
    
    for ( int i = 0; i < nums.size(); i++)
    {
        if ( nums[i] != i)
        {
            return i;
        }
    }
    return nums.size();

}

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        if ( 0 == nums.size())
        {
            return 0;
        }
        
        //return missingNumberxor(nums);
        return missingNumberbs(nums);
    }
};
