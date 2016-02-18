//Follow up for "Search in Rotated Sorted Array":
// What if duplicates are allowed?
//
// Would this affect the run-time complexity? How and why?
//
// Write a function to determine if a given target is in the array.


class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        int start = 0, end = nums.size()-1;
        
        while( start+1 < end)
        {
            int mid = start+(end-start)/2;
            
            if ( nums[mid] == target)
            {
                return 1;
            }
            else if ( nums[mid] < nums[end])
            {
                if ( nums[mid] < target && target <= nums[end])
                {
                    start = mid;
                }
                else
                {
                    end = mid;
                }
            }
            else if ( nums[mid] > nums[end])
            {
                if ( nums[mid] > target && target >= nums[start])
                {
                    end = mid;
                }
                else
                {
                    start = mid;
                }
            }
            else
            {
                //3123333
                //3333123
                //nums[mid] = 3, target = 1 can be in right or left partiton.
                end--;
            }
        }
        if ( nums[start] == target || nums[end] == target)
        {
            return 1;
        }
        
        return 0;
    }
};
