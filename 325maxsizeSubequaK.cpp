//
//
//Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead. 
//
//Example 1:
//
//
//Given nums = [1, -1, 5, -2, 3], k = 3,
// return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest) 
//
// Example 2:
//
//
// Given nums = [-2, -1, 2, 1], k = 1,
//  return 2. (because the subarray [-1, 2] sums to 1 and is the longest) 
//
//  Follow Up:
//   Can you do it in O(n) time? 
//

int maxSubArrayLen_n2(vector<int>& nums, int k)
{
    int max_len = 0;
    for ( int i = 0; i < (int)nums.size()-1; i++)
    {
        int sum = nums[i];
        if ( sum == k)
        {
            max_len = max(1, max_len);
        }
        for ( int j = i+1; j < nums.size(); j++)
        {
            sum += nums[j];
            if ( sum == k)
            {
                max_len = max(j-i+1, max_len);
            }
        }
    }
    return max_len;
}

int maxSubArrayLen_opt(vector<int>& nums, int k)
{
    unordered_map<int, vector<int> >hash_map;
    vector<int>presum(nums.size()+1, 0);
    for ( int i = 1; i <= nums.size(); i++)
    {
        presum[i] += presum[i-1]+ nums[i-1];
        hash_map[presum[i]].push_back(i);
    }
    
    int max_len = 0;
    for (int i = 0; i < presum.size(); i++)
    {
        int temp = k + presum[i];
        if ( hash_map.find(temp) != hash_map.end())
        {
            for ( int j = 0; j < hash_map[temp].size(); j++)
            {
                max_len = max(max_len, hash_map[temp][j] - i);
            }
        }
    }
    return max_len;
}

int maxSubArrayLen_opt2(vector<int>& nums, int k)
{
    unordered_map<int, int >hash_map;
    vector<int>presum(nums.size()+1, 0);
    int max_len = 0;
    for ( int i = 0; i <= nums.size(); i++)
    {
        presum[i] += (i==0)?0:(presum[i-1]+ nums[i-1]);
        if ( hash_map.find(presum[i]) == hash_map.end())
        {
            hash_map[presum[i]] = i;
        }
        
        if ( hash_map.find(presum[i]-k) != hash_map.end())
        {
            int index = hash_map[presum[i]-k];
            max_len = max(max_len, i-index);
        }
    }
    
    return max_len;
}

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) 
    {
        //return maxSubArrayLen_n2(nums, k);
        //return maxSubArrayLen_opt( nums,  k);
        return maxSubArrayLen_opt2( nums,  k);
    }
};



