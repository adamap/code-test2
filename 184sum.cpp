//
//
//
//
//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
//Note:
//
//Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡ b ¡ c ¡ d)
//The solution set must not contain duplicate quadruplets.
//
//    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
//
//        A solution set is:
//            (-1,  0, 0, 1)
//            (-2, -1, 1, 2)
//            (-2,  0, 0, 2)
//


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        
        for ( int i = 0; i <= (int)nums.size()-4; i++)
        {
            
            int first = nums[i];
            
            if ( i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            for ( int j = i+1; j <= (int)nums.size()-3; j++)
            {
                int second = nums[j];
                
                if ( j > i+1 && nums[j] == nums[j-1])
                {
                    continue;
                }

                int start = j+1, end = nums.size()-1;

                while(start < end)
                {
                    int tempsum = first+second+nums[start]+nums[end];
                    if ( tempsum == target )
                    {
                        vector<int>set;
                        set.push_back(first);
                        set.push_back(second);
                        set.push_back(nums[start]);
                        set.push_back(nums[end]);
                    
                        result.push_back(set);
                    
                        end--;
                        start++;
                        while(end > start && nums[end] == nums[end+1])
                        {
                            end--;
                        }
                        while(end > start && nums[start] == nums[start-1])
                        {
                            start++;
                        }
                    }
                    else if ( tempsum > target )
                    {
                        end--;
                    }
                    else
                    {
                        start++;
                    }
                }
            }
        }
        
        return result;
        
    }
};                    
