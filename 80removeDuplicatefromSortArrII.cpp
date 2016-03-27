//
//
//Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?
//
// For example,
//  Given sorted array nums = [1,1,1,2,2,3], 
//
//  Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length. 
//
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        // it is sorted array
        if (nums.size() < 3)
        {
            return nums.size();
        }
        
        int end = 1;
        
        for ( int i = 2; i < nums.size(); i++)
        {
            if ( nums[i] != nums[end-1])
            {
                nums[++end] = nums[i];
            }
        }
        
        return end+1;
        
        
    }
};



