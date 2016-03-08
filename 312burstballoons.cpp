//
//
//Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent. 
//
//Find the maximum coins you can collect by bursting the balloons wisely. 
//
//Note: 
// (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
//  (2) 0 ¡ n ¡ 500, 0 ¡ nums[i] ¡ 100 
//
//  Example: 
//
//  Given [3, 1, 5, 8] 
//
//  Return 167 
//      nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//     coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
//
int calcSum(vector<int>& nums, int i)
{
    int temp  = nums[i];
    int left  = (i > 0)?nums[i-1]:1;
    int right = (i < nums.size()-1)?nums[i+1]:1;
    return temp*left*right;
}


//recursive time limit exceeded 
void maxCoins_helper(vector<int>& nums, int sum, int &maxsum) 
{
    if (nums.size() == 1)
    {
        if (sum+ nums[0] > maxsum)
        {
            maxsum = sum+ nums[0];
        }
        return;
    }
    
    for ( int i = 0; i < nums.size(); i++)
    {
        int temp1 = nums[i];
        int temp2 = calcSum(nums, i); 
        sum += temp2;
        nums.erase(nums.begin()+i);
        maxCoins_helper(nums, sum, maxsum);
        sum -= temp2;
        nums.insert(nums.begin()+i, temp1);
    }
        
}

int maxCoins_helper_dp(vector<int>& nums)
{
    int n = nums.size();

    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));

    //for (int left = n; left >= 1; left--)
    for (int right = 1; right <= n; right++)
    {
      //for (int right = left; right <= n; right++)
      for (int left = right; left >= 1; left--)
      {
        for (int k = left; k <= right; k++)
        {
          int leftsum  = dp[left][k - 1];
          int rightsum = dp[k + 1][right];

          dp[left][right] = max(dp[left][right], nums[left-1] * nums[k] * nums[right+1] + leftsum + rightsum);
        }
      }
    }
    return dp[1][n];
}

class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        //int sum = 0, maxsum = 0;
        //maxCoins_helper(nums, sum, maxsum);
        //return maxsum;
        return maxCoins_helper_dp(nums);
    }
};
