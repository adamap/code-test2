//
//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
//Try to solve it in linear time/space.
//
//Return 0 if the array contains less than 2 elements.
//
//You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
//
//
class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        if ( nums.size() <= 1)
        {
            return 0;
        }
        
        int min_element = INT_MAX;
        int max_element = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if ( nums[i] > max_element)
            {
                max_element = nums[i];
            }
            if ( nums[i] < min_element)
            {
                min_element = nums[i];
            }
        }
        
        int len = (max_element - min_element)/nums.size()+1;
        int n   = (max_element - min_element)/len+1;
        
        vector<vector<int>> bucket(n);
        
        for (int j = 0; j < nums.size(); j++)
        {
            int i = (nums[j] - min_element)/len;
            
            if (bucket[i].empty())
            {
                bucket[i].push_back(nums[j]);
                bucket[i].push_back(nums[j]);
            }
            else
            {
                if ( nums[j] < bucket[i][0])
                {
                    bucket[i][0] = nums[j];
                }
                if ( nums[j] > bucket[i][1])
                {
                    bucket[i][1] = nums[j];
                }
            }
        }
        
        int maxgap = 0;
        int prev = 0;
        int  i;
        for (i = 0; i < n; i++ )
        {
            if ( !bucket[i].empty())
            {
                prev = i;
                break;
            }
        }
        for ( ; i < n; i++)
        {
            if ( bucket[i].empty())
            {
                continue;
            }
            if ((bucket[i][0] - bucket[prev][1]) > maxgap)
            {
                maxgap = bucket[i][0] - bucket[prev][1];
            }
            prev = i;
        }
        return maxgap;
        
    }
};
