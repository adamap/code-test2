//
//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements. 
//
//For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0]. 
//
//Note:
//
//1.You must do this in-place without making a copy of the array.
//2.Minimize the total number of operations.
//


void swap(vector<int>& nums, int a, int b)
{
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b]= temp;
}

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        
        int start = 0, end = nums.size()-1;
        int index = -1;
        
        while ( start <= end)
        {
            if ( nums[start] != 0)
            {
                swap(nums, start++, ++index);
            }
            else
            {
                start++;
            }
        }
    }
};
