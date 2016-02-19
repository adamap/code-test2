//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note:
//
//Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡ b ¡ c)
//The solution set must not contain duplicate triplets.
//
//    For example, given array S = {-1 0 1 2 -1 -4},
//
//        A solution set is:
//            (-1, 0, 1)
//            (-1, -1, 2)
//

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>result;
        
        if ( 0 == nums.size())
        {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        for ( int i = 0; i < n -2; i++)
        {
            if ( i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            int firstelement = nums[i];
            
            int start = i+1, end = n-1;
            
            while ( start < end)
            {
                if (nums[start]+nums[end]+ firstelement == 0)
                {
                    vector<int>set;
                    set.push_back(nums[i]);
                    set.push_back(nums[start]);
                    set.push_back(nums[end]);
                    sort(set.begin(), set.end());
                    result.push_back(set);
                    start++;
                    end--;
                    while( start < end && nums[end] == nums[end+1])
                    {
                        end--;
                    }
                    while( start < end && nums[start] == nums[start-1])
                    {
                        start++;
                    }
                }
                else if (nums[start]+nums[end]+ firstelement > 0)
                {
                    end--;
                    while( start < end && nums[end] == nums[end+1])
                    {
                        end--;
                    }
                }
                else
                {
                    start++;
                    while( start < end && nums[start] == nums[start-1])
                    {
                        start++;
                    }
                }
            }
        }
        
        return result;        
    }
};
