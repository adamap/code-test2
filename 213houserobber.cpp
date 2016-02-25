//Note: This is an extension of House Robber.
//
//After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street. 
//
//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
int rob_dp2(vector<int>& nums)
{
    if (0 == nums.size())
    {
        return 0;
    }
    int n = nums.size();
    vector<int>dp(n, 0);
    
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for (int i = 2; i < n; i++ )
    {
        dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
    }
    
    return dp[n-1];
    
}

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if ( 0 == nums.size())
        {
            return 0;
        }
        if ( 1 == nums.size())
        {
            return nums[0];
        }
        vector<int>temp(nums);
        temp.pop_back();
        int max1 = rob_dp2(temp);
        temp = nums;
        temp.erase(temp.begin());
        int max2 = rob_dp2(temp);
        
        return (max1>max2)?max1:max2;
    }
};


