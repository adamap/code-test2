//
//
//
//
//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory. 
//
//For example,
// Given input array nums = [1,1,2], 
//
// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length. 
//
void swap(vector<int>& nums, int a, int b)
{
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if ( nums.size() == 0)
        {
            return 0;
        }
        
        int i = 0, j = 0;
        
        while ( i < nums.size())
        {
            if ( nums[i] != nums[j] )
            {
                swap(nums, ++j, i++);
                
            }
            else
            {
                i++;
            }
        }
        
        return j+1;
    }
};
