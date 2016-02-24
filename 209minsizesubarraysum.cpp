//Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum >= s. If there isn't one, return 0 instead. 
//
//For example, given the array [2,3,1,2,4,3] and s = 7,
// the subarray [4,3] has the minimal length under the problem constraint. 
//

int minSubArrayLen1(int s, vector<int>& nums)
{
    int start = 0, end = 0;
    int temp = 0;
        
    int minlen= INT_MAX;
    while (end < nums.size() || temp >= s )
    {
        if ( temp < s && end < nums.size())
        {
            temp += nums[end];
            end++;
        }
        else if ( temp >= s)
        {
            minlen = min(minlen, end-start);
            temp -= nums[start];
            start++;
        }
        else
        {
            break;
        }
    }
        
    if (minlen == INT_MAX)
    {
        return 0;
    }
    return minlen;
}


int minSubArrayLen2(int s, vector<int>& nums)
{
    int start = 0, end = 0;
    int temp = 0;
        
    int minlen= INT_MAX;
    while (end < nums.size()  )
    {
        while ( temp < s && end < nums.size())
        {
            temp += nums[end];
            end++;
        }

        while ( temp >= s && start < nums.size())
        {
            minlen = min(minlen, end-start);
            temp -= nums[start];
            start++;
        }
    }
    
    if (minlen == INT_MAX)
    {
        return 0;
    }
    return minlen;
}

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        //int ret = minSubArrayLen1( s,  nums);
        int ret = minSubArrayLen2( s,  nums);        
    }
};
