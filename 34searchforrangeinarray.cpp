//Given a sorted array of integers, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return [-1, -1].
//
//For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
//  return [3, 4]. 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> result(2, -1);
        int start = 0, end = nums.size()-1;
        
        while( start+1 < end)
        {
            int mid = start + (end-start)/2;
            
            if ( nums[mid] >= target)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
            
        }
        
        if ( nums[start] == target)
        {
            result[0] = start;
        }
        else if ( nums[end] == target)
        {
            result[0] = end;
        }
        else
        {
            return result;
        }
        
        
        start = 0; end = nums.size()-1;
        while( start+1 < end)
        {
            int mid = start + (end-start)/2;
            
            if (nums[mid] <= target)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        if ( nums[end] == target)
        {
            result[1] = end;
        }
        else if ( nums[start] == target)
        {
            result[1] = start;
        }
        
        return result;
        
    }
};
