//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int start = 0, end = nums.size()-1;
        
        while (start+1 < end)
        {
            int mid = start+(end-start)/2;
            
            if ( nums[mid] < nums[end])
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        if ( nums[start] > nums[end])
        {
            return nums[end];
        }
        return nums[start];
         
        
    }
};
