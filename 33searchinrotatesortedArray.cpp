//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search. If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.
//

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int start = 0, end = nums.size()-1;
        
        while( start + 1 < end)
        {
            int mid = start + (end-start)/2;
            
            if ( nums[mid] == target)
            {
                return mid;
            }
            else if ( nums[mid] < nums[end] )
            {
                if (target > nums[mid] && target <= nums[end])
                {
                    start = mid;
                }
                else
                {
                    end = mid;
                }
            }
            else if (nums[mid] > nums[start])
            {
                if (target < nums[mid] && target >= nums[start])
                {
                    end = mid;
                }
                else
                {
                    start = mid; 
                }
            }
        }
        
        if ( nums[start] == target)
        {
            return start;
        }
        else if (nums[end] == target)
        {
            return end;
        }
        else
        {
            return -1;
        }
        
    }
};
