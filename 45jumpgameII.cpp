//Given an array of non-negative integers, you are initially positioned at the first index of the array. 
//
//Each element in the array represents your maximum jump length at that position. 
//
//Your goal is to reach the last index in the minimum number of jumps. 
//
//For example:
// Given array A = [2,3,1,1,4] 
//
// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.) 
//
// Note:
//  You can assume that you can always reach the last index.

//DP solution time limit exceeded
int jumpII_dp(vector<int>& nums)
{
    if ( 0 == nums.size())
    {
        return 0;
    }
        
    int n = nums.size();
    vector<int>stepsjump(n, INT_MAX);
        
    stepsjump[0] = 0;
        
    for ( int i = 1; i < n; i++)
    {
        for ( int j = 0; j < i; j++)
        {
            if (stepsjump[j] != INT_MAX && j+nums[j] >= i )
            {
               stepsjump[i] = 1+stepsjump[j];
               break;
            }
        }
    }
        
    return stepsjump[n-1];
}


int jumpII_gd(vector<int>& nums)
{
    if ( 0 == nums.size())
    {
        return 0;
    }

    int end = 0, start = 0, jumps = 0;
    
    while ( end < nums.size()-1)
    {
        jumps++;
        int farthest = end;
        
        for ( int i = start; i <= end; i++)
        {
            if ( nums[i] + i > farthest)
            {
                farthest = nums[i] + i;
            }
        }
        
        // can not jump to end, return INT_MAX to indicate the problem
        if ( farthest <= end)
        {
            return INT_MAX;
        }
        
        start = end+1;
        end = farthest;
    }
    return jumps;    
    
}

class Solution {
public:
    int jump(vector<int>& nums) 
    {
        //return jumpII_dp(nums);
        return jumpII_gd(nums);
    }
};

