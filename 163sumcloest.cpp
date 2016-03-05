

//
//
//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//    For example, given array S = {-1 2 1 -4}, and target = 1.
//
//        The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//
//

int abs(int i)
{
    return (i<0)?(-i):i;
}

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int middiff = INT_MAX;
        
        int ret;
        
        for ( int i = 0; i <= nums.size()-2;i++)
        {
            int first = nums[i];
            
            int start = i+1, end= nums.size()-1;
            while (start < end )
            {
                int tempsum = first+ nums[start]+nums[end];
                if (tempsum == target )
                {
                    return target;
                }
                else if ( tempsum > target)
                {
                    end--;
                }
                else
                {
                    start++;
                }
                int diff = abs(tempsum-target);
                if ( diff < middiff)
                {
                    middiff = diff;
                    ret = tempsum;
                }
            }
        }
        
        return ret;
    }
};
