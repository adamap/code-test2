//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
int rob_dp1(vector<int>& nums) 
{
    if (0 == nums.size())
    {
        return 0;
    }
        
    vector<vector<int>>dp(nums.size(), vector<int>(2, 0));
        
    dp[0][0] = 0;
    dp[0][1] = nums[0];
        
    for ( int i = 1; i < nums.size(); i++)
    {
        dp[i][0] = max(dp[i][0], dp[i-1][1]);
        dp[i][0] = max(dp[i][0], dp[i-1][0]);
            
        dp[i][1] = max(dp[i][1], dp[i-1][0]+nums[i]);
    }
        
    return (dp[nums.size()-1][0]>dp[nums.size()-1][1])?dp[nums.size()-1][0]:dp[nums.size()-1][1];
}

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
        //return rob_dp1( nums);
        return rob_dp2( nums);
    }
};
