//A peak element is an element that is greater than its neighbors.
//
//Given an input array where num[i] ¡ num[i+1], find a peak element and return its index.
//
//The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
//You may imagine that num[-1] = num[n] = -¡.
//
//For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int start = 0, end = nums.size()-1;
        
        while(start+1 < end)
        {
            
            int mid = start+(end-start)/2;
            int left  = (mid >= 1)?nums[mid-1]:INT_MIN;
            int right = (mid < nums.size()-1)?nums[mid+1]:INT_MIN;
            
            if ( nums[mid] > left && nums[mid] > right)
            {
                return mid;
            }
            else if (nums[mid] > left && nums[mid] < right)
            {
                start = mid;
            }
            else 
            {
                end = mid;
            }
        }
        if ( nums[start] < nums[end])
        {
            return end;
        }
        return start;
        
    }
};
